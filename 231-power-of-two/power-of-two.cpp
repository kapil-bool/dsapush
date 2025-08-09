class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n<=0){
        return 0;
       }
       while(n>0){
         if(n==1){
            return 1;//kind of base case ban gaya
         }
         if(n%2==0){
            n=n/2 ;
         }
         else
          break;
       }
       return false;
    }
};