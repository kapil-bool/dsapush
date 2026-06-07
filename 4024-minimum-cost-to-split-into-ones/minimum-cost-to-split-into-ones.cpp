class Solution {
public:
    int minCost(int n) {
        //dp is shit here but if always 1 and n-1
        int nw=n-1;
         return   nw*(nw+1)/2 ;
    }
};