class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>prefix(nums.size());
        prefix[0]=0;
        int sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            prefix[i]=sum;
            sum+=nums[i];
        }
        int rsum=nums[n-1];
        for(int i=n-2;i>=0;i--){
            prefix[i]=abs(rsum-prefix[i]);
            rsum+=nums[i];
        }
        return prefix;
    }
};