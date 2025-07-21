class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for (char c : s) {
            int n = res.size();

            //ye basciaclly check kar hai for char more than 2 and eqaul or not 
            if (n >= 2 && res[n - 1] == c && res[n - 2] == c) {
                continue;
            }
            res += c;
        }
        return res;
    }
};
