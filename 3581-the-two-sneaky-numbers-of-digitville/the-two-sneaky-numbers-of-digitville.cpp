class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> store;
        for (int x : nums) {
            store[x]++;
            if (store[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};