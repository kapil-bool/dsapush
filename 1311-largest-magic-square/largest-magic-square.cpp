class Solution {
public:
    
    vector<vector<int>> row, col, grid;
    int n, m;

    //row col and diagnol all have to be cheked;
    bool validator(int x, int y, int k) {
        int target = row[x][y + k] - row[x][y];

        //rows
        for (int i = 0; i < k; i++) {
            if (row[x + i][y + k] - row[x + i][y] != target)
                return false;
        }

        //y one 
        for (int j = 0; j < k; j++) {
            if (col[x + k][y + j] - col[x][y + j] != target)
                return false;
        }

        //diagnol here 
        int d1 = 0, d2 = 0;
        for (int i = 0; i < k; i++) {
            d1 += grid[x + i][y + i];
            d2 += grid[x + i][y + k - 1 - i];
        }

        return d1 == target && d2 == target;
    }

    int largestMagicSquare(vector<vector<int>>& g) {
        //prefix sum completly
        grid = g;
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> tempRow(n, vector<int>(m + 1, 0));
        vector<vector<int>> tempCol(n + 1, vector<int>(m, 0));
        row = tempRow;
        col = tempCol;

        int ans = 1;
        //prefix done 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        //now brute force 
        for (int cap = 2; cap <= min(m, n); cap++) {
            bool found = false;
            for (int i = 0; i + cap <= n; i++) {
                for (int j = 0; j + cap <= m; j++) {
                    if (validator(i, j, cap)) {
                        found = true;
                        //store and break;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) ans = cap;
        }

        return ans;
    }
};
