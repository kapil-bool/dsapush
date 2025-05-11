class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Create DP table with n rows and amount+1 columns
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        
        // Base case initialization: When we use only the first coin
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];  // Minimum coins required to make amount 'i'
            } else {
                dp[0][i] = 1e9;  // A large value if it's not possible to make amount 'i'
            }
        }
        
        //0 case already done so satrt from 1
        for (int ind = 1; ind < n; ind++) {  // Iterating over coins
            for (int T = 0; T <= amount; T++) {  // Iterating over target amounts
                int not_take = dp[ind - 1][T];  // If we don't take the current coin
                int take = 1e9;  // Initially, set 'take' to a very large value
                if (coins[ind] <= T) {  // If the current coin can be used
                    take = 1 + dp[ind][T - coins[ind]];  // Take one coin and solve for remaining amount
                }
                dp[ind][T] = min(not_take, take);  // Minimize the number of coins
            }
        }

        // The answer will be in the bottom-right cell of the DP table
        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;  // If the answer is still a large value, return -1
    }
};
