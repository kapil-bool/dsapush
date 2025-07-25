class Solution {
public:
    bool isvalid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    int possible_x[4] = {1, -1, 0, 0};
    int possible_y[4] = {0, 0, 1, -1};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, 0, 0}); 

        while (!pq.empty()) {
            auto [current_effort, row, col] = pq.top();
            pq.pop();

            if (row == n - 1 && col == m - 1) return current_effort;

            for (int i = 0; i < 4; i++) {
                int new_r = row + possible_x[i];
                int new_c = col + possible_y[i];

                if (isvalid(new_r, new_c, n, m)) {
                    int newabseffort = abs(heights[new_r][new_c] - heights[row][col]);
                    int maxi = max(newabseffort, current_effort); //this one is actuallly a doubtefull thing 
                    

                    if (maxi < dist[new_r][new_c]) {
                        dist[new_r][new_c] = maxi;
                        pq.push({maxi, new_r, new_c});
                    }
                }
            }
        }

        return 0;
    }
};
