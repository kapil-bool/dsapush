typedef long long ll;
class Solution {
public:

    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (ll) k*abs(nums[0]-nums[n-1]);
    }
};