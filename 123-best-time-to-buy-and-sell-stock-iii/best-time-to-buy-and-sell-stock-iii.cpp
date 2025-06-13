class Solution {
public:
    vector<vector<vector<long long >>> dp;
    int helper(int index,vector<int>& prices,int  decider,int n,int transation){
        //base case
        if(index==n || transation==0) return 0;
        if (dp[index][decider][transation] != -1)
            return dp[index][decider][transation];
        long long profit=0;
        //now the main part
        if(decider==1){
            //
            profit=max(-prices[index]+helper(index+1,prices,0,n,transation),helper(index+1,prices,1,n,transation)+0);
        }
        if(decider==0){
            //this is where u will sell and transation will be completed
            profit=max(0+helper(index+1,prices,0,n,transation),prices[index]+helper(index+1,prices,1,n,transation-1));
        }

        return dp[index][decider][transation] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        //in this question u should be more like when is money in the hand and when it is going out of the hand
        //decider==1 is can buy and ==0 is to sell
        int n=prices.size();
         dp = vector<vector<vector<long long>>>(
            n, vector<vector<long long>>(2, vector<long long>(3, -1))
        );

        return helper(0,prices,1,n,2);

    }
};