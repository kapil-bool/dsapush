class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid){
        //base case
        if (i < 0 || j < 0) return INT_MAX;
        if(i==0 and j==0)return grid[0][0];
        if(dp[i][j]!=-1)return dp[i][j];
        //only two operation 
        //up
        int up= helper(i-1,j,dp,grid);
        int right=helper(i,j-1,dp,grid);
        return dp[i][j]=min(up,right)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        //memoization better option i think so
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1)); //two d array initiate ho gaya hai
        return helper(n-1,m-1,dp,grid);

    }
};