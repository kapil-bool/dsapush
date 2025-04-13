class Solution {
public:
    int findClosest(int x, int y, int z) {
        int for_1=abs(z-x);
        int for_2=abs(z-y);
        
        if(for_1>for_2)return 2;
        if(for_1==for_2)return 0;
        else return 1;

        
    }
};