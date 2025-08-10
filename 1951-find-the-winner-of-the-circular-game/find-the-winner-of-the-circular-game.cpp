class Solution {
public:
    int helper(int n,int k){
        if(n==1) return 0;
        int ans=helper(n-1,k);
        return (ans+k)%n;
    }
    int findTheWinner(int n, int k) {
        //clokwise  1 to n;
        //so its more like a pointer i keep on a ds and delte the one the pointer is on make a queue
        int ans=helper(n,k);
        return ans+1;

    }
};