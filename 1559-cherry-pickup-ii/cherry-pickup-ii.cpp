class Solution {
public:
    int helper(int i,int j1,int j2,int r, int c,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        //2 robot positions 
        //base case u reach end 
        if(j1<0 || j2<0 ||j1>=c|| j2>=c)return -1e8;
        if(i==r-1){
        //2 cases here also that are 
        if(j1==j2)  return grid[i][j1];
        else{
            return grid[i][j1]+grid[i][j2];
         }    
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=-1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int newJ1 = j1 + dj1;
                int newJ2 = j2 + dj2;
                int value = 0;

                if (j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }

                value += helper(i + 1, newJ1, newJ2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        //god mode 
        //dp array initalise 3d 
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1))); //damm 
        return helper(0,0,c-1,r,c,grid,dp);

    }
};