class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
      for (int i = 1; i <= n; i++) {
            sumodd += (2*i - 1); // odd number
            sumeven += (2*i);    // even number
        }
        return __gcd(sumodd, sumeven);
        
    }
};