class Solution {
public:
    int dp[11][2][11];
    int solver(string &s,int index,bool tight,int count_1){
        //base case
        if(index==s.size()) return count_1;
        if(dp[index][tight][count_1]!=-1) return dp[index][tight][count_1];
        int lower_b=0;
        //if tight is true then the max possible is to the idx[i]-'0' else till all 9
        int upper_b=(tight==1) ? s[index]-'0': 9;
        long long ans=0;
        
        for(int i=lower_b;i<=upper_b;i++){
            //tight true only if the present one is true and the ub is there
            //count one only if the index value is one 
           ans+=solver(s,index+1,(tight and i==upper_b),count_1+(i==1));
        }
          return dp[index][tight][count_1]=ans;
    }
    int countDigitOne(int n) {
        //upper bound  lower bound  ..tight index ans no fo ones these there are enough;
        string s=to_string(n);
        memset(dp, -1, sizeof(dp));
        return solver(s,0,1,0);
    }
};