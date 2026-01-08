class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum = 0;
        int length = INT_MAX; // if no any it will be int max only; then -1
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            int x = nums[right];
            mp[x]++;
            if (mp[x] == 1) {
                sum += x;
            }
            // shrink
            while (sum >= k) {
                length = min(length, right - left + 1);
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    sum -= nums[left];
                }
                // else no problem; keep it
                left++;
            }
        }

        if (length == INT_MAX) return -1;
        return length;
    }
};
