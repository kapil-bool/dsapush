class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        while(n){
            int curent=n%10;
            mp[curent]++;
            n/=10;
        }
        int ans=0;
        for(auto &i:mp){
            ans+=i.first*i.second;
        }
        return ans;
    }
};