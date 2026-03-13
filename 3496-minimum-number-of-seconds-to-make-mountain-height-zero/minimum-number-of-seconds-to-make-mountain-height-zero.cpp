typedef long long ll;

class Solution {
public:

    bool check(int mountainHeight, vector<int>& workerTimes, ll time) {

        ll total = 0;

        for (int t : workerTimes) {

            long double val = 1 + (long double)8 * time / t;
            ll k = (sqrt(val) - 1) / 2;

            total += k;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    ll binary_s(int mountainHeight, vector<int>& workerTimes) {

        ll low = 0;
        ll high = 1e18;
        ll ans = high;

        while (low <= high) {

            ll mid = (low + high) / 2;

            if (check(mountainHeight, workerTimes, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        return binary_s(mountainHeight, workerTimes);
    }
};