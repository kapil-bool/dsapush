class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        q.push({0, 0});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 8; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};
