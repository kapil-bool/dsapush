class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //har rabit pe count kitne honge actual -1
         unordered_map<int, int> freq;
        for (int ans : answers) {
            freq[ans]++;
        }

        int result = 0;
        for (auto [x, count] : freq) {
            int groupSize = x + 1;
            int groups = ceil((double)count / groupSize);
            result += groups * groupSize;
        }
        return result;
    }
};