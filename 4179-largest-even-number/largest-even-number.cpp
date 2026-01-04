class Solution {
public:
    string largestEven(string s) {
        int le = s.length();
        int i = 0;

        for (i = le - 1; i >= 0; i--) {
            if (s[i] == '2')  
                break;
        }

        if (i == -1) return "";

        return s.substr(0, i + 1);  
    }
};
