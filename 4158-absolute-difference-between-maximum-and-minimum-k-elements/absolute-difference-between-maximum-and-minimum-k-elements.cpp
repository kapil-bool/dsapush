class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int st=0;
        int end=nums.size()-1;
        int ans=0;
        while(k--){
           ans+=(nums[end]-nums[st]);
           end--;
           st++;
        }
        return ans;
    }
};