class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> store(37, 0);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int digit = i, sum = 0;
            while (digit != 0) {
                sum += digit % 10;
                digit /= 10;
            }
            store[sum]++;
        }

        int maxVal = *max_element(store.begin(), store.end());

        for (int i = 0; i < store.size(); i++) {
            if (store[i] == maxVal) {
                ans++;
            }
        }

        return ans;
    }
};
