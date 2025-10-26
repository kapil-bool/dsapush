class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        //frequency related question
        //even and odd must be equal first thing else np; [1,2,5], target = [4,1,3] differntly he solve honge that is clear
        if(nums==target) return 0;
        
           vector<long long> nums_odd, nums_even;
        vector<long long> target_odd, target_even;

        for (int x : nums) {
            if (x % 2) nums_odd.push_back(x);
            else nums_even.push_back(x);
        }

        for (int x : target) {
            if (x % 2) target_odd.push_back(x);
            else target_even.push_back(x);
        }

        sort(nums_odd.begin(), nums_odd.end());
        sort(target_odd.begin(), target_odd.end());
        sort(nums_even.begin(), nums_even.end());
        sort(target_even.begin(), target_even.end());

       long long ans = 0;
        for (int i = 0; i < nums_odd.size(); i++)
            ans += abs(nums_odd[i] - target_odd[i]) / 2;

        for (int i = 0; i < nums_even.size(); i++)
            ans += abs(nums_even[i] - target_even[i]) / 2;

        return ans / 2;
    }
};