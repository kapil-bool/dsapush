class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(long long i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
       long long n=nums.size();
       vector<long long>suffix(n,0);
       suffix[n-1]=nums[n-1];
       //done now start filling the the rest
       for(long long i=n-2;i>=0;i--){
          suffix[i]= min(suffix[i+1],(long long)nums[i]);
       }

       long long ans=LONG_MIN;
       for(int i=0;i<n-1;i++){
         if(prefix[i]-suffix[i+1]>ans){
            ans=prefix[i]-suffix[i+1];
         }
       }
        
        return ans;
     
    }
};