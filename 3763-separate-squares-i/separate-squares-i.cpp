class Solution {
public:
    double binary(double area, double upper,double lower,vector<vector<int>>& squares){
        for(int p=0;p<=60;p++){

        double mid=(upper+lower)/2;
        double area_cal=0.0;
        //3 cases will be here fall dontfall and in between other 2 are ok now the intersection on 
        for(auto &i:squares){
            double y=i[1];
            double l=i[2];
            double cal=y+l;

          if (mid <= y) {
                }
                else if (mid >= cal) {
                    area_cal += l * l;
                }
                else {
                    area_cal += (mid - y) * l;
                }
            }
            if (area_cal >= area)
                upper = mid;
            else
                lower = mid;

         
        }
        //mid out of bound 
         return lower;
    }
    double separateSquares(vector<vector<int>>& squares) {
        //total area area < and lesss accordinly move away and  acc to that move to or  away from that
        //area overlped is allowed ok
        //lowewr start one and upper is the last one 
        double area=0;
        double upper=-1e9;
        double lower=+1e9;
        for(double i=0;i<squares.size();i++){
             double y = squares[i][1];
             double l = squares[i][2];
             area += l * l;
             lower = min(lower, y);
             upper = max(upper, y + l);
        }
        return binary(area/2.0,upper,lower,squares);
    }
};