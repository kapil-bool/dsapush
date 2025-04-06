class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n, 1);       // dp[i] = size of largest subset ending at i
        vector<int> parent(n, -1);  // to reconstruct the path
        int maxLen = 1, lastIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the subset
        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

