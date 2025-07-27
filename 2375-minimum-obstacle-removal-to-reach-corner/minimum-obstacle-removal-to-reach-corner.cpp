class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
         vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        deque<pair<int, int>> dq; 
        
        cost[0][0] = 0;
        dq.push_front({0, 0});
        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();
            //4 direction now
            for(int i=0;i<4;i++){
             int new_x = x + dx[i], new_y = y + dy[i];
             //valid or not
               if(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n) {
                    // cost to move: grid[new_x][new_y]
                    int new_cost = cost[x][y] + grid[new_x][new_y];
                    if(new_cost < cost[new_x][new_y]) {
                        cost[new_x][new_y] = new_cost;
                        // 0 cost moves (empty) push front, obstacle push back
                        if(grid[new_x][new_y] == 0)
                            dq.push_front({new_x, new_y});
                        else
                            dq.push_back({new_x, new_y});
                    }
             

     
            }
            
        }
        }
        return cost[m-1][n-1];
    }
};