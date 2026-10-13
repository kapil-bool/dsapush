typedef long  long ll;

class Solution {
public:
    // ll<vector> custom sort()
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
             return abs(a)<abs(b);
        });
        ll ans=0;
        int index=nums.size();
        // for(auto &i:nums){
        //     cout<<i<<" ";
        // }
        // if(index%2){
            for(int i=0;i<index/2;i++){
                ans+=nums[i]*nums[i];
            }
              ans=-ans;
              for(int i=index/2;i<index;i++){
            ans+=nums[i]*nums[i];
             }
        //  }
        // else{
        //     for(int i=0;i<index/2;i++){
        //         ans+=nums[i]*nums[i];
        //     }
        //         ans=-ans;
        //      for(int i=index/2;i<index;i++){
        //        ans+=nums[i]*nums[i];
        // }
        // }
      
        return ans;
    }
};