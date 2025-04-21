class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ongoing=0;
        int y=0,x=0;
       
        for(int i=0;i<differences.size();i++){
           ongoing+=differences[i];
           x=max(x,ongoing);
           y=min(y,ongoing);
           //checking if its in place;  with the help of max possiblities;
           if((x-y)>upper-lower)return 0;

        }
        return (upper-lower)-(x-y)+1;

        // return count;

    }
};