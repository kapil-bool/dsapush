class Solution {
public:
    int helper(int left_i, int right_i, vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: only one element left
        if (left_i == right_i) return nums[left_i];
        if (dp[left_i][right_i] != INT_MIN) return dp[left_i][right_i];

        int pickLeft = nums[left_i] - helper(left_i + 1, right_i, nums, dp);

        //exactly here itslike i take the first one and then other two the the options of the oponets so i sub tractt it 
        int pickRight = nums[right_i] - helper(left_i, right_i - 1, nums, dp);

        return dp[left_i][right_i] = max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return helper(0, n - 1, nums, dp) >= 0;
    }
};
