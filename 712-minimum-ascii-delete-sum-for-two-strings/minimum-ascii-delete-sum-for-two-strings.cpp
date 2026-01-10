class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<int>suff1,suff2;
    int solve(int i, int j, string &s1, string &s2) {
       //3 cases both and skip i and skip 2;
       //skip matlab delete hoga 
       if(i==n){
         int sum=suff2[j];
          
         return sum;
       }
       if(j==m){
        int sum=suff1[i];
        
         return sum;
       }
       if(dp[i][j]!=-1) return dp[i][j];
       //when to skip if both are equal u skip no need 
       if(s2[j]==s1[i]){
           return dp[i][j]=solve(i+1,j+1,s1,s2);
       }
       int skipi=s1[i]+solve(i+1,j,s1,s2);
       int skipj=s2[j]+solve(i,j+1,s1,s2);
        
        dp[i][j]=min(skipi,skipj);
        return dp[i][j];

    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        dp.assign(n, vector<int>(m, -1));
        suff1.assign(n+1,0);
        suff2.assign(m+1,0);
        for(int i=n-1;i>=0;i--){
            suff1[i]=suff1[i+1]+s1[i];
        }
        for(int i=m-1;i>=0;i--){
            suff2[i]=suff2[i+1]+s2[i];
        }
        return solve(0, 0, s1, s2);
    }
};
