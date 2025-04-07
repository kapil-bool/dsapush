class Solution {
public:
    bool helper(vector<int>& nums,vector<vector<int>>&dp,int index,int target){
        //base case
        if(target==0)return true;
        if(target<0||index<0)return false;

        if(dp[index][target]!=-1)return dp[index][target];
        //2 opt of command
       bool include = helper(nums, dp, index - 1, target - nums[index]);
        bool exclude = helper(nums, dp, index - 1, target);

        return dp[index][target] = (include || exclude);

    }
    bool canPartition(vector<int>& nums) {
        //tabulation
        int n=nums.size();
         int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        // int n = nums.size(); 
        //create a vector now
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(nums,dp,n-1,target);

    }
};