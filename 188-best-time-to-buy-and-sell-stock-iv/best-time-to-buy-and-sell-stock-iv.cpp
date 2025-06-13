class Solution {
public:
    int helper(int n, int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (canBuy == 1) {
                        dp[index][canBuy][cap] = max(
                            -prices[index] + dp[index + 1][0][cap],  
                            dp[index + 1][1][cap]                    
                        );
                    } else {
                        dp[index][canBuy][cap] = max(
                            prices[index] + dp[index + 1][1][cap - 1], 
                            dp[index + 1][0][cap]                     
                        );
                    }
                }
            }
        }

        return dp[0][1][k]; 
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        return helper(n, k, prices);
    }
};
