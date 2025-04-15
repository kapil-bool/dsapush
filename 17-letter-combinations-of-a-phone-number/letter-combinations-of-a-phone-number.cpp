class Solution {
public:
    unordered_map<char, string> mpp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void helper(int index, vector<string>& ans, string& s, string& digits) {
        // base case: if we reached the end
        if (index == digits.size()) {
            ans.push_back(s); // Push before return
            return;
        }

        // letters for current digit
        string letter = mpp[digits[index]];
        for (auto& i : letter) {
            s.push_back(i);                   // Add char
            helper(index + 1, ans, s, digits); // Recurse
            s.pop_back();                     // Backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s = "";
        if (digits.size() == 0) return {};
        helper(0, ans, s, digits);
        return ans;
    }
};
