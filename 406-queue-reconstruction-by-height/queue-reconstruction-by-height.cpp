// class Solution {
// public:
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
//     }
// };
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort people: tallest first, then k ascending
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> ans;
        // Insert each person at index = k
        for (auto &p : people) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans;
    }
};
