class Solution {
public:
    //index and score
  int solve(vector<int>& slices, int start, int end, int k, vector<vector<int>>& dp) {
        if (k == 0 || start > end) return 0;
        if (dp[start][k] != -1) return dp[start][k];

        // pick current slice
        int take = slices[start] + solve(slices, start + 2, end, k - 1, dp);
        // skip current slice
        int skip = solve(slices, start + 1, end, k, dp);

        return dp[start][k] = max(take, skip);
    }

    int maxSizeSlices(vector<int>& slices) {
        //so here the selection of other player depentd what i chose must be an 2N from start and end to make this happen
        //ok will do this later i knoww the logic of this 
        //if current pick is i then next one shoukld be n-1 circular here
        //circlusr condtuon
        int n = slices.size();
        int k = n / 3;

        //  exclude last slice
        vector<vector<int>> dp1(n, vector<int>(k + 1, -1));
        int case1 = solve(slices, 0, n - 2, k, dp1);

        //  exclude first slice
        vector<vector<int>> dp2(n, vector<int>(k + 1, -1));
        int case2 = solve(slices, 1, n - 1, k, dp2);

        return max(case1, case2);
    }
};