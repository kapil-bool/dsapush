class Solution {
public:
    int bitwiseComplement(int n) {
        //mask one xor and return will work
        if (n==0) return 1;
        int mask=(1<<(32-__builtin_clz(n)))-1;
        

        //compilent it and return thats it 
        //take the compliment 
        return mask^n; 
    }
};