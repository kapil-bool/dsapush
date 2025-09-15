class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        bool canType = 1;
        for (char c : text) {
            if (c == ' ') {
                res += canType;
                canType = 1;
            }
            if (brokenLetters.find(c) != string::npos) 
                canType = 0;
        }
        return res + canType;
    }
};