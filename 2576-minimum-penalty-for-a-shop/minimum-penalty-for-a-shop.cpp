class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n + 1, 0);  
        vector<int> suffix(n + 1, 0);  

       
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
        }

        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }
        int minPenalty = INT_MAX;
        int bestHour = 0;
        for (int i = 0; i <= n; ++i) {
            int penalty = prefix[i] + suffix[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};
