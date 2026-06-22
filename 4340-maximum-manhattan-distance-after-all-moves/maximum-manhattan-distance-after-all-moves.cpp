class Solution {
public:
    int maxDistance(string moves) {
        unordered_map<char,int>mp;
        for(auto &i:moves){
            mp[i]++;
        }
        int max1;
        int max2;   
        int add=mp['_'];
        // for(auto){
            int u=mp['U'];
            int d=mp['D'];
            int l=mp['L'];
            int r=mp['R'];
            //cancel out right
            max1=max(u-d,d-u);
            max2=max(l-r,r-l);

        
        return max1+max2+add;
    }
};