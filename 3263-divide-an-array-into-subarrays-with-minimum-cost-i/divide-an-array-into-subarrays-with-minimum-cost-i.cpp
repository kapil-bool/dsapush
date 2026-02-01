class Solution {
public:
    int minimumCost(vector<int>& nums) {
        //first elemnt to contribute karega he 
        int answer=nums[0];
        //next two elemnts now;
        int s1=1e9;
        int s2=1e9;
        sort(nums.begin()+1,nums.end());

        return answer+nums[1]+nums[2];

    }
};