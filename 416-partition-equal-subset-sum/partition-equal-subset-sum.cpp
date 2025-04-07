class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); // -1 = unvisited
        return helper(n - 1, target, nums, dp);
    }

    bool helper(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index < 0 || target < 0) return false;

        if (dp[index][target] != -1)
            return dp[index][target]; // Already solved

        bool include = helper(index - 1, target - nums[index], nums, dp);
        bool exclude = helper(index - 1, target, nums, dp);

        return dp[index][target] = (include || exclude);
    }
};
