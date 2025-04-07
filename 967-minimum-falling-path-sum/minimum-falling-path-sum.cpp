class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //now just go for the tabulation approch as the memo is giving me TLE
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //base case filling
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }

        // 3 variable
        for(int i=1;i<n;i++){
         for(int j=0;j<m;j++){

        int up=dp[i-1][j];//jayega to down he
        //also have to check if the value dont go out of range
        int up_l=(j>0)? dp[i-1][j-1]:INT_MAX; 
        int up_r= (j<n-1)?dp[i-1][j+1]:INT_MAX;

        dp[i][j]=matrix[i][j]+min({up,up_l,up_r});
         }
        }
        //will return the last row as soon as reached
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};