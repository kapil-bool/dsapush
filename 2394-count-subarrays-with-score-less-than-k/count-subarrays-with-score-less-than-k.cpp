class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        //ya to ye find kar le ki konsa max hai before that all are possible;
          long long ans = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                ++left;
            }
            ans += (right - left + 1);
        }

        return ans;
    }
};