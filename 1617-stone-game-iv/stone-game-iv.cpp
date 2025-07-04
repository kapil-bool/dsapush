class Solution {
public:
 bool helper(int n,vector<int>& dp){
     if(n==0)return false ;
     if(dp[n]!=-1)return dp[n];
     for(int i=1;i*i<=n;i++){
          if(!helper(n-(i*i),dp)){
            //this means atleasat one is making it 0 so 
             return  dp[n]=true;
          }
     }
     return dp[n]=false;
 }
    bool winnerSquareGame(int n) {
        //damm this question is good more of like check all the possiblites here just for the first player if it is making 1
        //return ture else make it false
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }

};