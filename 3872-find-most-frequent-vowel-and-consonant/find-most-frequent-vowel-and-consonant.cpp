class Solution {
public:
    bool isvowel(char i) {
        return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> nonv;
        unordered_map<char, int> v;

        for (char c : s) {
            if (isvowel(c))
                v[c]++;
            else
                nonv[c]++;
        }

        int vcount = 0;
        for (auto& p : v)
            vcount = max(vcount, p.second);

        int nvcount = 0;
        for (auto& p : nonv)
            nvcount = max(nvcount, p.second);

        return vcount + nvcount;
    }
};