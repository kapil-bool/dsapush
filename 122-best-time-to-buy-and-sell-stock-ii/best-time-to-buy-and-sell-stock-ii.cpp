class Solution {
public:
    int helper(vector<int>& prices,vector<vector<long long>>& dp,int index,int buy,int n){
        //base case
        if(index==n){
            //buy not possible so u 
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        long long profit=0;
        //now do the buy no buy and they to will have two option
        if(buy==1){
            //now u have to sell this means
            profit=max(0+helper(prices,dp,index+1,1,n), prices[index]+helper(prices,dp,index+1,0,n));
        }
        if(buy==0){
            //go buy 
            profit=max(0+helper(prices,dp,index+1,0,n), -prices[index]+helper(prices,dp,index+1,1,n));
        }
       dp[index][buy]=profit;
       return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return helper(prices,dp,0,0,n);
    }
};