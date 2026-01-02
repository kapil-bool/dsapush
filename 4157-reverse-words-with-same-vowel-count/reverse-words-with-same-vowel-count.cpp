class Solution {
public:
  bool valid_vowel(char c) {
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    string reverseWords(string s) {
        //esc esc start and end for the between and for the last one esc and  new line 
        //esc=space 
        int count_infirst=0;
        int i=0;
       int n=s.size();
      while (i < n && s[i] != ' ') {
            if (valid_vowel(s[i])) count_infirst++;
            i++;
        }
       //remaing one 
       int pointer_second=i+1;
       int shadow_count=0;
        for (int ptr = i + 1; ptr <= n; ptr++) {

            if (ptr < n && valid_vowel(s[ptr]))
                shadow_count++;

            if (ptr == n || s[ptr] == ' ') {

                if (shadow_count == count_infirst) {
                    reverse(s.begin() + pointer_second,
                            s.begin() + ptr);
                }

                shadow_count = 0;
                pointer_second = ptr + 1;
            }
        }
       return s;
    }
};
