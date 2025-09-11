class Solution {
public:
  bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        vector<char>vowel_possiblites;
        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                vowel_possiblites.push_back(s[i]);
            }
        }

        sort(vowel_possiblites.begin(),vowel_possiblites.end());

        int vowel_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                s[i] = vowel_possiblites[vowel_index++];
            }
        }
    return s;
    }
};