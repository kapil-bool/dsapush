class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int right=0,left=0;
        while(right<nums.size()){
            //only zero and one
            //if one and not one
            if(nums[right]==nums[left] and nums[left]==1){
                //right ++
                right++;

            }
            else{
                //right==0 
                count=max(count,right-left);
                right++;
                left=right;
            }
        }
        ///last case
                count=max(count,right-left);

        return count;
    }
};