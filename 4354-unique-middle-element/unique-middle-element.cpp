class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int middle=nums.size()>>1;
        unordered_map<int,int>mp;
        for(auto &i:nums){
           mp[i]++;
        }
        // cout<<mp[middle];
        return mp[nums[middle]]==1;
    }
};