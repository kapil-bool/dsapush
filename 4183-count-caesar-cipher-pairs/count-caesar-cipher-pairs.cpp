class Solution {
public:
    long long countPairs(vector<string>& words) {
       //relative ordere same here
       unordered_map<string,long long>mp;
       long long ans=0;
       for(auto & i: words){
          int   base=i[0]-'a';
          string wrd="";
          //now next one
           for(auto & j:i){
             //so crete the differnce mach it if it is incremted u add it
              char calp=(j-'a'- base+26)%26 +'a';
              //push into the temp string
              wrd.push_back(calp);
           }
           mp[wrd]++;
       }
       for(auto &i:mp){
          auto cnt=i.second;
          ans += cnt * (cnt - 1) / 2;
       }
       return ans;
    }
};