class Solution {
public:
    int passwordStrength(string s) {
        int ans=0;
        int n=s.size();
        map<char,int>mp;
         for(auto &i:s){
             mp[i]++;
         }
         for(auto &i : mp){
            int ch=i.first;
            if(islower(ch)){
                ans+=1;
            }
            else if(isupper(ch)){
                ans+=2;
            }
            else if(isdigit(ch)){
                ans+=3;
            }
            else{
                ans+=5;
            }
        }
        return ans;
    }
};