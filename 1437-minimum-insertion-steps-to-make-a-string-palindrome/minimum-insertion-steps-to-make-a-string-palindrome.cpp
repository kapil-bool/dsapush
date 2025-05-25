class Solution {
public:
// If we know the longest palindromic sub-sequence is x and the length of the string is n then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.
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
        //return the above and minus it from the total length of any string
    }
    int minInsertions(string s) {
          string s2 = s;
        reverse(s2.begin(), s2.end());

       int to_be_minus= longestCommonSubsequence(s,s2);
       return s.size()-to_be_minus;
        
    }
};