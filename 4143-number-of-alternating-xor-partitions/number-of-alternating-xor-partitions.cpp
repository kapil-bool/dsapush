typedef long long ll;
const int mod = 1e9 + 7;
class Solution {
public:
    //partion dp here 
    vector<vector<ll>>dp;
    vector<int>prefix;
    int n;
    int t1;
    int t2;
    int helper(int index, int whicht){
        if(index==n) return 1;
        if(dp[index][whicht]!=-1) return dp[index][whicht];
        ll ans=0;
        int target=(whicht==0? t1:t2);
        //n^2
        for(int i=index;i<n;i++){
              //if the xor is equal the next thing is index++ and chenge the stage ^1
               int xr = prefix[i + 1] ^ prefix[index]; //cancel out the prev one simply ;
              if(xr==target){
                  ans = (ans + helper(i + 1, whicht ^ 1)) % mod;
              }
        }
        return dp[index][whicht]=ans;// general template
    }
        
    
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
         n=nums.size();
        t1=target1;
        t2=target2;
        prefix.assign(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]^nums[i];
            //a postion further is stored thst it ;
        }
        dp.assign(n+1,vector<ll>(2,0)); //only 2 states are there therfore 2
        // return helper(0,0);
        unordered_map<int,ll>mp0,mp1;
        dp[n][0]=dp[n][1]=1;
        mp0[prefix[n]]=1;
        mp1[prefix[n]]=1;
        for(int i=n-1;i>=0;i--){
            //from the back now store the prefix in them and use look up;
            dp[i][0]=mp1[prefix[i]^target1]%mod;
            dp[i][1]=mp0[prefix[i]^target2]%mod;
            //also have to fill the map with current i;
            mp0[prefix[i]] = (mp0[prefix[i]] + dp[i][0]) % mod;
            mp1[prefix[i]] = (mp1[prefix[i]] + dp[i][1]) % mod;
        }

           return dp[0][0];
    }
};