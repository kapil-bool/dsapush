class Solution {
public:
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //4 direction are there once u obtain a strigh one go in the staight direction that can be done by 
        //first letting know if the cel adj is free or not if it is then fix the one cordinate simultanously and explore count them and add them with walls and gaurds and minus from m*n 
        //mark them visited also core bfs and dfs approch kinga but i dont ned to use that
        //a valid box will be when not out of bound no gaurd and no w;
         vector<vector<int>> grid(m, vector<int>(n, 0));
       for(auto &g : guards ){
int x = g[0], y = g[1];
grid[x][y] = 1;
}


for(auto &w : walls ){
int x = w[0], y = w[1];
grid[x][y] = 2;
}
        int new_x[4]={0,0,1,-1};
        int new_y[4]={1,-1,0,0};
        //marks the gaurded by 3 
        for(auto &i :guards){
            int x=i[0],y=i[1];
          for(int j=0;j<4;j++){
             //4 direction and now checking and exeuting
             int nw_x=x+new_x[j];
             int nw_y=y+new_y[j];
              while(nw_x >= 0 && nw_y >= 0 && nw_x < m && nw_y < n &&
                      grid[nw_x][nw_y] != 1 && grid[nw_x][nw_y] != 2) 
                {
                    if(grid[nw_x][nw_y] == 0) grid[nw_x][nw_y] = 3; 
                    //same direction ->staight line continuation
                    nw_x += new_x[j];
                    nw_y += new_y[j];
                }

          }
        }
        //now just count it 
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) ans++;
            }
        }

        return ans;

    }
};