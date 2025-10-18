class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int curr = nums.back(); 

        for (int i = 0; i < k; i++) {
            sum += curr;
            curr++;
        }

        return sum;
    }
};
