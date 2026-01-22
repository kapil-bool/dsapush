class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (nums.size() > 1) {
            bool safe = true;
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    safe = false;
                    break;
                }
            }

            if (safe) break;

            int summ = INT_MAX;
            int index = -1;

            for (int i = 0; i + 1 < nums.size(); i++) {
                int cur = nums[i] + nums[i + 1];
                if (cur < summ) {
                    summ = cur;
                    index = i;
                }
            }
            nums[index] = summ;
            nums.erase(nums.begin() + index + 1);
            count++;
        }

        return count;
    }
};
