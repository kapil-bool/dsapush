class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &i:words){
            int sum=0;
            for(auto &x:i){
                sum+=weights[x-'a'];
            }
            ans+=('z'-sum%26);
        }
        return ans;
    }
};