typedef long long ll;
class Solution {
public:
     ll dp[20][2][2];
     string s;

     ll helper(int index,bool tight, bool leadingzero){
        //base case=
        if(index==s.size())return !leadingzero;
        if(dp[index][tight][leadingzero]!=-1) return dp[index][tight][leadingzero];
        int upperbound=tight?s[index]-'0':9;
        ll ans=0;
        for(int i=0;i<=upperbound;i++){
            bool nt= tight and (i==upperbound);
            //me leading zeros are there skip;
            if(leadingzero and i==0){
                ans+=helper(index+1,nt,1);
            }
            else{
                //dont allow this time;
                if(i==0){
                    continue;
                    //take another one;
                }
                ans+=helper(index+1,nt,0);
            }
        }
        return dp[index][tight][leadingzero]=ans;
     }
  
    long long countDistinct(long long n) {
        //2 tites up and zero one 
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return helper(0,1,1);
    }
};