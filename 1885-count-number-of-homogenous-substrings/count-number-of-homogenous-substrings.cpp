class Solution {
public:
    int countHomogenous(string s) {
        long long res = 0;
        long long currentCount = 1;  // Count of consecutive characters (starting with the first character)

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i-1]) {
                // If the current character is the same as the previous one, increase the count
                currentCount++;
            } else {
                // If not, add the number of homogenous substrings for the previous block of characters
                res += (currentCount * (currentCount + 1)) / 2;
                currentCount = 1;  // Reset the count for the new character block
            }
        }

       
        res += (currentCount * (currentCount + 1)) / 2;

       
        return res % 1000000007;
    }
};
