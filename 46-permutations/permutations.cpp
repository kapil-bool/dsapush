class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int>& nums, vector<int> &current, vector<bool> &ischosen) {
        // base case
        if(current.size() == nums.size()) {
            ans.push_back(current);
            return;    
        }

        for(int i = 0; i < nums.size(); i++) {
            if(ischosen[i]) continue;

            ischosen[i] = true;
            current.push_back(nums[i]);

            helper(ans, nums, current, ischosen);

            // backtrack
            ischosen[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> ischosen(n, false);
        helper(ans, nums, current, ischosen);
        return ans;
    }
};
