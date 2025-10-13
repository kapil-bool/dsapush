class Solution {
public:
    int dp[11][2][2][2][1023];
    int solver(string &s,int index,bool tight,bool rep,bool ledz,int mask){
        if(index==s.size()) return rep;
        if(dp[index][tight][rep][ledz][mask]!=-1) return dp[index][tight][rep][ledz][mask];

        int lb=0;
        int ub=(tight) ? s[index]-'0' : 9;
        int ans=0;

        for(int i=lb;i<=ub;i++){
            if(ledz && i==0){
               
                ans += solver(s, index+1, (tight && i==ub), rep, true, mask);
            }
            else{
                bool pr = (mask >> i) & 1;
                
                ans += solver(s, index+1, (tight && i==ub), (rep || pr), false, (mask | (1 << i)));
            }
        }
        return dp[index][tight][rep][ledz][mask]=ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solver(s, 0, true, false, true, 0);
    }
};
