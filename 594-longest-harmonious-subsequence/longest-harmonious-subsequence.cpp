class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &p: mp){
            int key = p.first;
            if(mp.count(key + 1)){
                count = max(count, mp[key] + mp[key + 1]);
            }
        }

        return count;
    }
};