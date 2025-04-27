class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(long long i=1;i<nums.size()-1;i++){
             //scope ke bahar na jaye
             if((nums[i])==(nums[i-1]+nums[i+1])*2) count++;
             
        }
      return count;
    }
};