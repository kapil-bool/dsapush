class Solution {
public:
int helper(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int count=1e9; //it should be minimum
    ///so i need to generte also
    for(int i=1;i*i<=n;i++){
        int square = i * i;
        int current_count=1+helper(n-square,dp);
        count=min(count,current_count);
    }
    return dp[n]=count;
}
    int numSquares(int n) {
        //like the smaller sqaaure will make the answer 
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};