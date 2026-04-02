class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));
        //base 
        for(int k=0;k<3;k++){
            if(coins[0][0]>=0) dp[0][0][k]=coins[0][0];
            else{
                //same as memo
                dp[0][0][k]=coins[0][0];
                if(k>0) dp[0][0][k]=max(dp[0][0][k],0);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                for(int k=0;k<3;k++){
                    int best_prev = -1e9;

                    if(i>0) best_prev=max(best_prev,dp[i-1][j][k]);
                    if(j>0) best_prev=max(best_prev,dp[i][j-1][k]);

                    if(coins[i][j]>=0){
                        dp[i][j][k]=max(dp[i][j][k], best_prev + coins[i][j]);
                    }
                    else{
                        // take loss
                        dp[i][j][k]=max(dp[i][j][k], best_prev + coins[i][j]);

                        // neutralize
                        if(k>0){
                            int best_prev_k = -1e9;
                            if(i>0) best_prev_k=max(best_prev_k,dp[i-1][j][k-1]);
                            if(j>0) best_prev_k=max(best_prev_k,dp[i][j-1][k-1]);

                            dp[i][j][k]=max(dp[i][j][k], best_prev_k);
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};