class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool vowel=false;
        bool consonet=false;
        for(int i=0;i<word.size();i++){
            if(word[i]=='@' or word[i]=='$' or word[i]=='#')  return false;
            else if(word[i]=='a' or word[i]=='A' or word[i]=='e' or word[i]=='E' or word[i]=='o' or word[i]=='O' or word[i]=='i' or word[i]=='I' or  word[i]=='u' or  word[i]=='U'){
                vowel=true;
            }
            else if(isalpha(word[i])) {
                consonet = true;
            }
            


        }
        return (vowel and consonet);
    }
};