class Solution {
public:
    int minMoves2(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];  // Middle element

        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }

        return moves;
    }
};