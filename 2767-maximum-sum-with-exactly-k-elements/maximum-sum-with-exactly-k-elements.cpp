class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int curr = nums.back(); 

        return curr*k+(k*(k-1)/2);
    }
};
