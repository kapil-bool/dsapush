class Solution {
public:
    vector<vector<int>> ans;

    void helper(int index, vector<int>& nums, vector<int>& temp) {
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }

        
        unordered_set<int> visited;

        for (int i = index; i < nums.size(); i++) {
            // check the condition
            if (!temp.empty() && nums[i] < temp.back()) continue; 
            // this means not to be includeed

            // equal walo ko bhi handel karna badega for that a seen wala function on the temp use it
            // if the temp one is already in the ans wer and valid u skip it avoid duplicacy;
            if (visited.count(nums[i])) continue; 
            visited.insert(nums[i]);

            temp.push_back(nums[i]);
            helper(i + 1, nums, temp);  
            temp.pop_back();

            // [[4,6],[4,6,7],[4,6,7,7],[4,7] so skip is there 
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // condtion are greater and size more than 2
        // subsequence 
        vector<int> temp;
        helper(0, nums, temp);
        return ans;
    }
};
