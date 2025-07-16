class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int noofOdd = 0, noofEven = 0, alternate = 0;
        int parity = -1;

        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i] & 1;
            
            if (p == 0) {
                noofEven++;
                if (parity == 1 || parity == -1) alternate++;
            } else {
                noofOdd++;
                if (parity == 0 || parity == -1) alternate++;
            }

            parity = p;
        }

        return max({noofOdd, noofEven, alternate});
    }
};
