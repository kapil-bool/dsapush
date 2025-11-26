class Solution {
public:
    int n, m, K;
    const int MOD = 1e9 + 7;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int helper(int i, int j, int rem) {
       
        int newRem = (rem + grid[i][j]) % K;

       
        if (i == n - 1 && j == m - 1) {
            return (newRem == 0) ? 1 : 0;
        }

        if (dp[i][j][newRem] != -1) 
            return dp[i][j][newRem];

        long long ans = 0;
      
        if (i + 1 < n) ans = (ans + helper(i + 1, j, newRem)) % MOD;
        
        if (j + 1 < m) ans = (ans + helper(i, j + 1, newRem)) % MOD;

        dp[i][j][newRem] = (int)ans;
        return dp[i][j][newRem];
    }

    int numberOfPaths(vector<vector<int>>& g, int k) {
        grid = g;
        K = k;
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(K, -1)));
       
        return helper(0, 0, 0);
    }
};
