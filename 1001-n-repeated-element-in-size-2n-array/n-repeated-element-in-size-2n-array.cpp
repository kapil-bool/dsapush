class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
       
       for(auto &i:mp){
        if(i.second==n) return i.first;
       }
        return -1;
    }
};
//
