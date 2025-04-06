class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& triangle,int n){
        //base case
        //LAST ROW REACHED 
        
        if(i==n-1)return triangle[i][j];
        //2 call will also be initated;
        if(dp[i][j]!=-1)return dp[i][j];

        int btm=helper(i+1,j,dp,triangle,n);
        int btm_one=helper(i+1,j+1,dp,triangle,n);
        return dp[i][j]=min(btm,btm_one)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //2d matrix is what is given
        int n=triangle.size();//no of rows
        // int m=triangle[0].size(); wont work here
        vector<vector<int>>dp(n,vector<int>(n,-1));
         return helper(0,0,dp,triangle,n);
    }
};