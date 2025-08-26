class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //so here brute force
        //store the i there only
        int maxlen=0;
        int area=0;
        for(auto &i : dimensions){
            int length = i[0];
            int width  = i[1];
           int diagnal=((length*length) + (width*width));
           if(maxlen<diagnal){
               maxlen=diagnal;
               area= length*width;
           }
           else if(maxlen==diagnal){
            area=max(area, length*width);
           }
          
        }
        return area;
    }
};