class Solution {
public:
    int helper(int index,vector<int>& nums, vector<vector<int>> & dp,int n,int previous){
        //base case
        if(index==n)return 0;
        if(dp[index][previous+1]!=-1)return dp[index][previous+1];

        //now the pick not pick condition
        int not_take=helper(index+1,nums,dp,n,previous)+0;
        int take=0;
        if(previous==-1 || nums[previous]<nums[index])
          take=1+helper(index+1,nums,dp,n,index);
        

        return dp[index][previous+1]=max(take,not_take);
      

    }
    int lengthOfLIS(vector<int>& nums) {
        //a prev will be maintaned here so do the shifting of -1
        int n =nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,nums,dp,n,-1);
    }
};