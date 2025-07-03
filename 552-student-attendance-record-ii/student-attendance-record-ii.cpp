class Solution {
public:
    const int MOD = 1e9 + 7;

    int helper(int day, int absents, int lates, int n, vector<vector<vector<int>>>& dp) {
        if (absents > 1 || lates > 2) return 0;  // invalid path
        if (day == n) return 1;  // valid record of length n

        if (dp[day][absents][lates] != -1) return dp[day][absents][lates];

        long long total = 0;

      
        total += helper(day + 1, absents, 0, n, dp);

      
        total += helper(day + 1, absents + 1, 0, n, dp);

        //  Add 'L' (if we haven't had 2 consecutive lates)
        total += helper(day + 1, absents, lates + 1, n, dp);

        return dp[day][absents][lates] = total % MOD;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 0, 0, n, dp);
    }
};
