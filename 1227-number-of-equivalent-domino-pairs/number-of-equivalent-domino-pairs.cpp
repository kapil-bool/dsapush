class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
       unordered_map<int,int>store;
       int count=0;
       for(auto i:dominoes){
         int a=i[0],b=i[1];
        //  lets creaate a key
         int key=min(a,b)*10+max(a,b);
         //first count then increment;
         count+=store[key];
         store[key]++;
       }
       return count;
    }
};