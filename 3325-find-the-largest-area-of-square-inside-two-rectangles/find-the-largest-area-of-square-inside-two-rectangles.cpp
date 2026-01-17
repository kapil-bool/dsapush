class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        //intersection and after that posiible or not a square min(kenth and breth of intersection
        //intersection should check for the start of other should be more than that of start of first one and less then end of other  yaa that it 
        long long  area=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //boundary set 
                //corners of all will participate;
                int x1=max(bottomLeft[i][0],bottomLeft[j][0]);
                int y1=max(bottomLeft[i][1],bottomLeft[j][1]);
                int x2=min(topRight[i][0],topRight[j][0]);
                int y2=min(topRight[i][1],topRight[j][1]);


                //check intersection;
                if(x1<x2 and y1<y2){
                    //intesection hai soo procede
                    long long contributer=min(x2-x1,y2-y1);
                    area=max(area,1LL*contributer*contributer );
                }
            }


        }
        return area;
    }
};