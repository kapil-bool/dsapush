class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target[i]) mp[(nums[i])]++;
        }
        return mp.size();
    }
};