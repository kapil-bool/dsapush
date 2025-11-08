class Solution {
public:
    int minimumOneBitOperations(int n) {
        //grey code one this is 
        //its more like reverse mapping here
        int ans = 0;
        while (n > 0) {
         ans ^= n;
        n >>= 1;
             }
       return ans;

    }
};