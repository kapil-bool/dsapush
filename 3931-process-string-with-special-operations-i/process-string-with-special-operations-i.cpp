class Solution {
public:
    string processStr(string s) {
        //simulate this 
        string ans="";
        for(auto &i:s){
            if(i=='*'){
                if(ans.size())
                ans.pop_back();
            }
            else if(i=='#'){
                ans+=ans;
            }
            else if(i=='%'){
                 reverse(ans.begin(),ans.end());
            }
            else{
                ans+=i;
            }
        }
        return ans;
    }
};