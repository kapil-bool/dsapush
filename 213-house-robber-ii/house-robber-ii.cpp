class Solution {
public:
    int helper(int index,vector<int>& nums, vector<int> &dp){
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int take=0;
        take=nums[index]+helper(index-2,nums,dp);
         int not_take=helper(index-1,nums,dp);

        return dp[index]=max(take,not_take);

    }
    int rob(vector<int>& nums) {
        //so basic pick not pick here also all u have to do is //first and last 
        //repeated subaray are there
        //0 to n-2 and 1 to n-1 here they are to cases store the answer in two variable retur  ythe max
        int n=nums.size();
        if(n==1) return nums[0];
        //specifing the end is important here
        vector<int>dp1(n,-1);
        vector<int> case1(nums.begin(), nums.end() - 1);
        int p_1=helper(n-2,case1,dp1);
        vector<int>dp2(n,-1);
        vector<int> case2(nums.begin()+1, nums.end());
        int p_2=helper(n-2,case2,dp2);


        return max(p_1,p_2);

    }
};