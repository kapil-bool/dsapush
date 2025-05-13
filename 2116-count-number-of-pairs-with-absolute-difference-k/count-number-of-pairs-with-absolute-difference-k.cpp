class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> v(101 + 2 * k, 0);
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += v[nums[i] + 2 * k] + v[nums[i]];
            v[nums[i] + k]++;            
        }

        return count;
    }
};