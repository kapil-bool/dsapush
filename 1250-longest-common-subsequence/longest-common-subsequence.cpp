class Solution {
public:
   //memo givving tle so will do the tabulation
//    int helper(string text1, string text2,int i,int j, vector<vector<int>> & dp){
//     //base case when u reach zero it matches or not so basciclly the base case be when it is negative
//     if(i<0 || j<0)return 0;
//     //same pick no pick kinda but no pick also offer 2 possiblities
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(text1[i]==text2[j]){
//         return dp[i][j]=1+helper(text1,text2,i-1,j-1,dp);
//     }
//     //not pick two possiblites max one to select
//      return dp[i][j]=0+max(helper (text1,text2,i,j-1,dp),helper (text1,text2,i-1,j,dp));

//    }
    int longestCommonSubsequence(string text1, string text2) {
        //lets finsish this with memoization
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base cases is still same here insted shifting of index is done
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int j=0;j<m;j++) dp[0][j]=0;
        //now the remaing one from 1 to n
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //pick not pick
                 if(text1[i-1]==text2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
    }
          //not pick two possiblites max one to select
          else
          dp[i][j]=0+max(dp[i-1][j] ,dp[i][j-1] );
            }
        }
        return dp[n][m];
    }
};