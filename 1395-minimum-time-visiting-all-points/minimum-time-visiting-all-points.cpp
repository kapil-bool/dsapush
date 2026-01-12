class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //first and second ine if cany cordinate is same them then 1  as 1<1.2
        //increment till as the one u reaced has been decided
        int time=0;
        for(int i=1;i<points.size();i++){
            int dx=points[i-1][0];
            int sx=points[i][0];
            int dy=points[i-1][1];
            int sy=points[i][1];
            //now differnce will do the trick here 
            //int 1.2->1 so take only the max one ;
            int differx=abs(dx-sx);
            int differy=abs(dy-sy);

            time+=max(differx,differy);
        }
        return time;

        
    }
};