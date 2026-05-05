class Solution {
public:
    bool isvowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return 1;

        }
        return 0;
    }
    //comparator bano
    //exact postion 
    string sortVowels(string s) {
       unordered_map<char,int>freq;
       //first ocuramce also ;
       unordered_map<char,int>pos;

       for(int i=0;i<s.size();i++){
         if(isvowel(s[i])){
             freq[s[i]]++;
         }
         if(pos.find(s[i])==pos.end()){
            //not there so make it count;
            pos[s[i]]=i;
         }
       }
       vector<char>v;
       for(auto &c:freq){
          v.push_back(c.first);
       }
       sort(v.begin(),v.end(),[&](char a, char b){
          if(freq[a]!=freq[b]) return freq[a]>freq[b];
          return pos[a]<pos[b]; //else on postion 
       });
       vector<char>sortedv;
       for(char c:v){
          for(int i=0;i<freq[c];i++){
             sortedv.push_back(c);
          }
       }
        int j=0;
       for(int i=0;i<s.size();i++){
         if(isvowel(s[i])){
            s[i]=sortedv[j];
            j++;
         }
       }
       return s;
    }
};