class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //negative hai to pick the biggest abd add it
        int n=nums.size();
        return nums[n-1]+nums[n-2]-nums[0];
    }
};