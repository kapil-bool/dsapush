class Solution {
public:
   int helper(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int mini=1e9;

      for(int k=i;k<=j;k++){
         int cost=cuts[j+1]-cuts[i-1]+helper(i,k-1,cuts,dp)+helper(k+1,j,cuts,dp);
         mini=min(mini,cost);
      }
      return dp[i][j]=mini;
 
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); //0(1)
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end()); //nlogn;
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        
        return helper(1,cuts.size()-2,cuts,dp);
    }
};