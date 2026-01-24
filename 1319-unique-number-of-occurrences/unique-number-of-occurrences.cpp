class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int>mp;
       set<int>st;
       for(int i=0;i<arr.size();i++){
         mp[arr[i]]++;
       }
       bool flag=1;
       for( auto &i:mp){
         if(st.count(i.second))  flag=0;
         else{
            st.insert(i.second);
         }
       }
       return flag;
    }
};