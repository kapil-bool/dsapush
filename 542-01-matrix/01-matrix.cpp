class Solution {
public:
    int rown[4] = {-1, 1, 0, 0};
    int coln[4] = {0, 0, -1, 1};

    bool isvalid(int i, int j, int row, int col) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //so approch is just found the nearest one and distance of that cell minus the currnt can do it and update it in 
        //the ans
        // BFS is naturally suited for shortest path in unweighted grids (like this one). 
        //start from the top 0 0 and all 0 are 0 itself so add them to the que
        int m = mat.size(), n = mat[0].size();  
         queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, 0));
         for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
                    else{
                         dist[i][j] =1e9;
                    }
            }
        }
        while(!q.empty()){
             auto [x, y] = q.front();
             q.pop(); 
             
             for(int i=0;i<4;i++){
                int newr=x+rown[i];
                int newc=y+coln[i];
                //ifthis is valid then find 
          if (isvalid(newr, newc, m, n) && dist[newr][newc] > dist[x][y] + 1){
                    //so i have alreay done alloted a value like 1e9 so for each of this i am able current distance>new distance where it is one thanmake the changes
                     dist[newr][newc]=dist[x][y]+1;
                     q.push({newr,newc});

                }
             }
        }
        return dist;
    }
};