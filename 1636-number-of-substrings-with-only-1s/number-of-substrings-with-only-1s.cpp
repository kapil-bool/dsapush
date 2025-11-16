class Solution {
public:
    int numSub(string s) {
        //approch is like 1 1 1 1 keep on incresing the count and onces it is 0 ompute with n*N+1/2 i guess this will be enough
        int count=0;
        int ans=0;
        const int mod=1e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
            else{
               ans += (1LL * count * (count + 1) / 2)% mod;
                count=0;
            }
        }
        ans += (1LL * count * (count + 1) / 2)% mod;
        return ans;
    }
};