class Solution {
public:
    string nums;
    int n;
    int dp[35][2][2];

    int helper(int index, int tight, int prev) {
        if (index == n) return 1;

        int &res = dp[index][tight][prev];
        if (res != -1) return res;

        int upperB = (tight ? nums[index] - '0' : 1);
        int ans = 0;

        for (int i = 0; i <= upperB; i++) {
            if (prev == 1 && i == 1) continue;
            int nextTight = (tight && (i == upperB));
            ans += helper(index + 1, nextTight, i);
        }

        return res = ans;
    }

    int findIntegers(int num) {
        
       
        if (num == 0) return 1;

        nums = "";
        while (num) {
            nums += (num % 2) + '0';
            num /= 2;
        }
        reverse(nums.begin(), nums.end());
        n = nums.size();

        memset(dp, -1, sizeof(dp));
        return helper(0, 1, 0);
    }
};
