class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        //well shifting is the the answer here 
        vector<bool>ans;
        int checked=0;
        //all 0 now 
        for(int i=0;i<nums.size();i++){
            checked = (checked * 2 + nums[i]) % 5; 
             ans.emplace_back(checked == 0);
            
        }

        return ans;
    }
};