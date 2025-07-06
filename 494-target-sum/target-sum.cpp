class Solution {
public:
    int helper(int index, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {
       if(index==nums.size()){
         return sum==target ?1 :0;
       };
       if(dp[index][1000+sum]!=-1) return dp[index][1000+sum];
    //    if(sum>target) return 0;
       //here u add into the sum +1000 +nums[index];
       int add=helper(index+1,sum+nums[index],nums,target,dp);
       int sub=helper(index+1,sum-nums[index],nums,target,dp);
       //here they both may possiblr contain sum values so add them both

       return dp[index][1000+sum]=add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1)); // shifted by +1000 to handle negatives
        //so if its -ve 5 it will be stored at 995
        return helper(0, 0, nums, target, dp);
    }
};
