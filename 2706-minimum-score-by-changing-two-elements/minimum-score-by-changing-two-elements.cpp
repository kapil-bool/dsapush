class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        //smallest one and largest one 
        //1 4 5 7 8 -> 
        //smllest 3 
        //largest 7
      sort(nums.begin(), nums.end());
        int n = nums.size();
        
        //1 4 5 7 8;
        //zero to always rahega min wala now the max one 
        int case1 = nums.back() - nums[2];
        int case2 = nums[nums.size() - 3] - nums[0];
        int case3 = nums[nums.size() - 2] - nums[1];
         return min({case1, case2, case3});  
    }
};