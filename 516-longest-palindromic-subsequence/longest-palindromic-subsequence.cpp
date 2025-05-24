class Solution {
public:

 int longestCommonSubsequence(string text1, string text2) {
        //lets finsish this with memoization
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base cases is still same here insted shifting of index is done
        
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
    int longestPalindromeSubseq(string s) {
        //very good no need to create any sub string and all;
        /* bbbab  and babbb
        cbbd and dbbc
        so make one reverssal and then let the substring do the magic*/
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return longestCommonSubsequence(s,s2);

    }
};