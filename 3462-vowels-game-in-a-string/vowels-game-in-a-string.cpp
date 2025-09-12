class Solution {
public:
   
    bool doesAliceWin(string s) {
        //hints give to much 
        int count_vowels=0;
      for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count_vowels++;
            }
        }
        if(count_vowels ==0 or count_vowels&1 !=1) return false;
        return true;
    }
};