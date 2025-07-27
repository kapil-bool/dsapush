class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        // Directions:   R    L     D     U
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        cost[0][0] = 0;
        pq.push({0, {0, 0}});  

        while(!pq.empty()){
            int curr_cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            
            if(curr_cost > cost[x][y]) continue;

            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_y >= 0 && new_x < m && new_y < n){

                    int extra = (grid[x][y] == i + 1) ? 0 : 1;
                    //same direction or the other all 4 possiblites will be explored here 
                    int new_cost = curr_cost + extra;
                    if(new_cost < cost[new_x][new_y]){
                        //u found a new one update it 
                        //validy is already checked for the new one that it is the matrix part
                        cost[new_x][new_y] = new_cost;
                        pq.push({new_cost, {new_x, new_y}});
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};
//its just relaxation question not something taht haptic 
