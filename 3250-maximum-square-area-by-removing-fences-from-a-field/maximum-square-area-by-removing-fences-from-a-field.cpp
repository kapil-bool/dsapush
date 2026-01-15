class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> heights;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                heights.insert(hFences[j] - hFences[i]);
            }
        }
        int best = 0;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int width = vFences[j] - vFences[i];
                if (heights.count(width)) {
                    best = max(best, width);
                }
            }
        }
        if (best == 0) return -1;
        return (1LL * best * best) % MOD;
    }
};

