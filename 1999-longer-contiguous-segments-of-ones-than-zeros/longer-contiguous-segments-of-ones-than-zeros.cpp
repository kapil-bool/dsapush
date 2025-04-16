class Solution {
public:
    bool checkZeroOnes(string s) {
        int max1 = 0, max0 = 0;
        int left = 0, right = 0;
        int n = s.size();

        while (right < n) {
            if (s[right] == s[left]) {
                right++;
            } else {
                if (s[left] == '1') {
                    max1 = max(max1, right - left);
                } else {
                    max0 = max(max0, right - left);
                }
                left = right;
            }
        }

        // Final group check after loop ends
        if (s[left] == '1') {
            max1 = max(max1, right - left);
        } else {
            max0 = max(max0, right - left);
        }

        return max1 > max0;
    }
};
