typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
         int n = nums.size();
        vector<long long> positions(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                positions[i] = (long long)nums[i] + d;
            } else {
                positions[i] = (long long)nums[i] - d;
            }
        }

         sort(positions.begin(), positions.end());
          long long prefixSum = 0;
    long long result = 0;

    for (int i = 0; i < n; ++i) {
        // For each position, total distance to previous elements
        result = (result + i * positions[i] % MOD - prefixSum + MOD) % MOD;
        prefixSum = (prefixSum + positions[i]) % MOD;
    }

    return result;
        
    }
};
