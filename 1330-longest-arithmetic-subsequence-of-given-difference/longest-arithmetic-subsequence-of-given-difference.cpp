class Solution {
public:
    int helper(int index,int previous,vector<int>& arr, int difference,vector<vector<int>> &dp){
        //base case
        if(index==arr.size())return 0;
        if(dp[index][previous+1]!=-1) return dp[index][previous+1];
        int take=0;
        if(previous ==-1 || arr[index]==arr[previous]+difference){
            take=1+helper(index+1,index,arr,difference,dp);
        }
        int nottaKe_=helper(index+1,previous,arr,difference,dp);

        return dp[index][previous+1]=max(take,nottaKe_);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        //exactly its take not take and satisy the condtion and +1 here bcz u will be maintaing the prev here
        // since it is a memory limit exedd using tabulation
        int n=arr.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return helper(0,-1,arr,difference,dp);
         int maxLen = 0;
         
        unordered_map<int, int> dp;
        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            maxLen = max(maxLen, dp[num]);
        }
        return maxLen;
    }
};