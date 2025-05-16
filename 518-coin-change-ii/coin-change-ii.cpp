class Solution {
public:
    int solver(int index, int target,vector<int>& coins,vector<vector<int>>& dp){
        //base case that u can reach the 
        //if target is reached zero at a base index
        if(index==0) return target % coins[0]==0;
        //take 
        if(dp[index][target]!=-1)return dp[index][target];
        long long nottake=solver(index-1,target,coins,dp);
        long long take=0;
        //condition of target se equal ho yaa less
        if(coins[index]<=target){
            take=solver(index,target-coins[index],coins,dp);
        }

        return dp[index][target]=take+nottake;


    }
    int change(int amount, vector<int>& coins) {
        //same target question 
        int n=coins.size();
        //memoization code n-1 se start karna hai
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solver(n-1,amount,coins,dp);
    }
};