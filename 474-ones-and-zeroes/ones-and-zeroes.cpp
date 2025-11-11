class Solution {
public:
 int dp[601][101][101];  //mentioned constians
    pair<int,int> checker(string s){
        int zer=0;
        int ones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zer++;
            else{
                ones++;
            }
        }
        return {zer,ones};
    }
    int helper(int index,int m,int n,vector<string>& strs){
        if(index==strs.size()) return 0;
        if(dp[index][m][n]!=-1) return dp[index][m][n];
        int take=0;
        auto[zer,one]= checker(strs[index]);
        if(m>=zer and n>=one)
        take=1+helper(index+1,m-zer,n-one,strs);

        int not_take=helper(index+1,m,n,strs);

        return dp[index][m][n]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // classsic take not take only if take reduce m and n accordingly
         memset(dp, -1, sizeof(dp));
        return helper(0,m,n,strs);
    }
};