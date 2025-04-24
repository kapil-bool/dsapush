class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_set<int> count(nums.begin(), nums.end());
        int n = count.size();

        int right = 0;
        int left = 0;
        int ans = 0;

        while (right < nums.size()) {
            mp[nums[right]]++;

            while (mp.size() == n) {
                // All subarrays from left to right are valid
                ans += (nums.size() - right);

                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }

            right++;
        }

        return ans;
    }
};

