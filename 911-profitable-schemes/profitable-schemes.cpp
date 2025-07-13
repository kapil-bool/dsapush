class Solution {
public:
    int dp[101][101][101];
    int MOD = 1e9 + 7;
    int helper(int index,int current_n,int currentprofit,int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(index==profit.size()) {
            //here return the current profit 
            return currentprofit >= minProfit ? 1 : 0;
        };
        if(dp[index][current_n][currentprofit]!=-1) return dp[index][current_n][currentprofit];
        //same condtion pick not pick
        int way=helper(index+1,current_n,currentprofit,n,minProfit,group,profit);
        //now the taking part
        //condtion is just about the n so satisfy that only if it does addd profit and incremt the count of cuurrnt _n
        //so here are no of ways u take it not take it is same u take +1 to the way

        if(current_n+group[index]<=n){
            //yippi
            int new_profit=min(currentprofit+profit[index],minProfit);
            way+=helper(index+1,current_n+group[index],new_profit,n,minProfit,group,profit); //two changind variable are here also   
            way=way % MOD;

        }

        return dp[index][current_n][currentprofit]=way;


    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        //2 constrints aare here one is of n min profit
        //well all the constrianrs are 101 so make it directly and assign them -1
        memset(dp, -1, sizeof(dp));
        return helper(0,0,0,n,minProfit,group,profit);
    }
};