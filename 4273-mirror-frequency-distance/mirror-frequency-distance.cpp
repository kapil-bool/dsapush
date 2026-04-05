class Solution {
public:
    int mirrorFrequency(string s) {
        //subtract and find better 
        //oo here i need to pair and find kind 
        //97 122 a to 
        //idea is to count and see the compint in circular 
        //differnt procced karna padega
        unordered_map<char,int>mp;
        for(auto &i : s){
            mp[i]++;
        }
         int ans=0;
        for(char i='a';i<='z';i++){
            char ch = 'z'-(i-'a'); //complent 
            if(i<=ch){
                 ans+=abs(mp[i]-mp[ch]);
            }
        }

        for(char i='0';i<='9';i++){
             char ch='9'-(i-'0');
             if(i<=ch){
                 //check hai otherswise /2;
                ans+=abs(mp[i]-mp[ch]);
                 
             }
        }
        return ans;
    }
};