class Solution {
public:
    vector<double>prefix;
    int n;
    vector<vector<double>>dp;
    double helper(int index,int k){
          if(index==n) return 0;
         if(k==1){
            return (prefix[n]-prefix[index])/(double)(n-index);
         }
         if(dp[index][k]!=-1) return dp[index][k];
         double ans=0;
         //all cases are here 
         for(int j=index;j<n;j++){
            //now with remaing k-1 
            //j chanhe hoga naa
            double average=(prefix[j+1]-prefix[index])/(j-index+1);
            ans=max(ans,average+helper(j+1,k-1));

         }
         return dp[index][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        //too much brute force here idea is trying each partion here
        n=nums.size();
        dp.assign(n+1,vector<double>(k+1,-1));
        prefix.assign(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        return helper(0,k);
    }
};