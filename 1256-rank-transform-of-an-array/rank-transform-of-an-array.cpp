class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        int pos = 1;
        for (auto& pair : mp) {
            for (int index : pair.second) {
                arr[index] = pos;
            }
            pos++;
        }
        return arr;
    }
};