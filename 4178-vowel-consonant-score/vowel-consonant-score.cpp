class Solution {
public:
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

    int vowelConsonantScore(string s) {
        int v=0;
        int c=0;
         for(int i=0;i<s.size();i++){
             if(isVowel(s[i])) v++;
             else if(isalpha(s[i])){

                c++;
             }

         }

         if(c>0) return floor(v/c);

         return 0;
    }
};