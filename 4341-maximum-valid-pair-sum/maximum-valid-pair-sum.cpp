typedef long long ll;
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        // int mazi=0;

        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((j-i)>=k){
        //               mazi=max(mazi,nums[i]+nums[j]);
        //         }
        //     }
        // }
        // return mazi;
        //find if valid and till that time tiss mean all prev i ill be valid now new + the old i max nums[i] so it become constant and bam 
          
         int n=nums.size();
         vector<ll>prefix(n);
         prefix[0]=nums[0];
         for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],(ll)nums[i]);
         }
         //now the satisfaction;
         ll ans=0;
         for(int j=k;j<n;j++){
            ans=max(ans,prefix[j-k]+(ll)nums[j]);
         }
         return ans;
    }
};