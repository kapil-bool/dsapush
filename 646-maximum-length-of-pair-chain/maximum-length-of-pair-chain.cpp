class Solution {
public:
    int helper(int current, int previous, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if (current == pairs.size()) return 0;

        if (dp[current][previous + 1] != -1) 
            return dp[current][previous + 1];

        int take = 0;
        if (previous == -1 || pairs[current][0] > pairs[previous][1]) {
            take = 1 + helper(current + 1, current, pairs, dp);
        }

        int not_take = helper(current + 1, previous, pairs, dp);

        return dp[current][previous + 1] = max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, pairs, dp);
    }
};
