class Solution {
public:
    const int MOD  =1e9+7;
    int dp[31][1001];
    int helper(int dice,int target,int k){
        if(dice==0) {
            return (target==0);
        }
        if(target<0) return 0;
        if(dp[dice][target]!=-1) return dp[dice][target];
        //now here thr thong is target reduction
        //1 dice will cover each possinlty from 1 to k faces;
        int ans=0;
        for(int i=1;i<=k;i++){
            //faces
            ans=(ans+helper(dice-1,target-i,k))%MOD;
        }

        return dp[dice][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        //2d dp
        //n and k ;
        //target --; 
        memset(dp,-1,sizeof(dp));
        return helper(n,target,k);
    }
};