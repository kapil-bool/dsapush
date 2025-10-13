class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        //sort and compare will also work here
       vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
              string a = words[i], b = words[i-1];
              sort(a.begin(),a.end());
              sort(b.begin(),b.end());
              if(a!=b) ans.push_back(words[i]);

        }
        return ans;
    }
};