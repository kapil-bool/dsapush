class Solution {
public:
    vector<vector<int>>ans;
    void helper(int index,vector<int>&nums,vector<int>&temp){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            if (i > index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            helper(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //like using a set is a vice desion at first but slower sort them and look for duplicates
        //like in [1 2 2]->to are 1,2;1,2 so i have to avoid it it simply means see the duplicates
        vector<int>temp;
        sort(nums.begin(),nums.end());
        //needee  nlogn all other are n 
        helper(0,nums,temp);
        return ans;
    }
};