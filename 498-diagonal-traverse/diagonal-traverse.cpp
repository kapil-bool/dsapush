class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool upward = true;
        int i = 0, j = 0;

        vector<int> ans;
        ans.reserve(n * m);

        for (int k = 0; k < n * m; k++) {
            ans.push_back(mat[i][j]);

            if (upward) {                  
                if (j == m - 1) { i++; upward = false; }
                else if (i == 0) { j++; upward = false; }
                else { i--; j++; }
            } else {                     
                if (i == n - 1) { j++; upward = true; }
                else if (j == 0) { i++; upward = true; }
                else { i++; j--; }
            }
        }
        return ans;
    }
};
