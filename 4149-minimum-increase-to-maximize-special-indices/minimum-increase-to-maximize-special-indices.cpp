typedef long long ll;

class Solution {
public:
    int n;
    vector<int> nums;
    vector<pair<int, ll>> dp;

    ///pick not pick only here ;
    pair<int,ll> helper(int index){
        if(index >= (n - 1)){
            return {0,0};
        }
        if(dp[index].first != -1){
            return dp[index];
        }
        pair<int,ll> take = helper(index + 2);

        //here a cost is there and u have makde the index valid
        take.first += 1;
        take.second += max(
            0LL,
            max(nums[index - 1], nums[index + 1]) +
            1LL - nums[index]
        );

        pair<int,ll> ntake = helper(index + 1);

        pair<int,ll> ans;

        if (take.first > ntake.first) {
            ans = take;
        }
        else if (take.first < ntake.first) {
            ans = ntake;
        }
        else {
            ans = (take.second <= ntake.second ? take : ntake);
        }

        return dp[index] = ans;
    }

    long long minIncrease(vector<int>& nums) {
        //dynamic programming LOCAL SOLUTIONS ARE FAILING HERE
        //things is it is dependend on 2 factors
        this->nums = nums;
        n = nums.size();
        dp.assign(n + 5, {-1, -1});
        auto ans = helper(1);
        return ans.second;
    }
};