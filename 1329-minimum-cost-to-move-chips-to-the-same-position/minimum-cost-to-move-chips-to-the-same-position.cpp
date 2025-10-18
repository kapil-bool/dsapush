class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        //same postion so the where max chips are allocated send there and to -2 +2 
        int parity_1=0;
        int parity_0=0;
        int n=position.size();
        for(int i=0;i<n;i++){
         if(position[i] & 1 ) parity_1++;
         else parity_0++;
        }
        //now making the moves
        return min(parity_1,parity_0);
    }
};