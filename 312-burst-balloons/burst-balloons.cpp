class Solution {
public:
    int helper(int i, int j,vector<int>& nums,  vector<vector<int>> &dp){
        //base case
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int max_coins=0;
        for(int k=i;k<=j;k++){
           int coins=nums[i - 1] * nums[k] * nums[j + 1] +helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp);

           max_coins=max(max_coins,coins);
        }
        return dp[i][j]=max_coins;;
    }
    int maxCoins(vector<int>& nums) {
        //take the whole then i and j
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
      return   helper(1,nums.size()-2,nums,dp);
    }
};