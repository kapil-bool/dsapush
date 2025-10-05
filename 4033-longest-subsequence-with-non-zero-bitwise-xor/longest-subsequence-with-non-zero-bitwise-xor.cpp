class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        //bits related hai karta hu ise bhi
       int n = nums.size();
        int totalXor = 0;
        for (int x : nums) totalXor ^= x;

       if (totalXor != 0) return n;

       
        bool allZero = true;
        for (int x : nums) {
            if (x != 0) {
                allZero = false;
                break;
            }
        }

        return allZero ? 0 : n - 1;
    }
};