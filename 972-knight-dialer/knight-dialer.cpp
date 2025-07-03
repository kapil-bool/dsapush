class Solution {
public:
      const int MOD = 1e9 + 7;

   
    vector<vector<int>> moves = {
        {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9},
        {}, {0,1,7}, {2,6}, {1,3}, {2,4}
    };
    int helper(int remaining, int digit,vector<vector<int>>&dp){
   ///base casen==1;
       if(remaining==1)return 1;
       if (dp[remaining][digit] != -1) return dp[remaining][digit];
       long long ans=0;
       for(auto i: moves[digit]){
          ans=ans+helper(remaining-1,i,dp);
          ans=ans % MOD;
       }
        return dp[remaining][digit]=ans;
       
       
    }
    int knightDialer(int n) {
        ///map and store them starting and ending are contributing and already fro like n=3 06->2,7 dont include the  
        //  repeated  one and u get the answer so * and # pe travel kar sakte ho but cant include them   
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
         long long total = 0;
        for (int digit = 0; digit <= 9; ++digit) {
            total = (total + helper(n, digit, dp)) % MOD;
        }

        return total;
    }
};