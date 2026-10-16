class Solution {
public:
   
    bool threeFibonacciSum(int n) {
        int first=0;
        int second=1;
        int possi=0;;
        while(possi<n){
            possi=first+second;
            if((possi*2LL)==n) return 1;
            first=second;
            second=possi;
        }
    return 0;
    }
};
