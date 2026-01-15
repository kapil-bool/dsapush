class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //squre shaped maximize 
        //hbar or 
        //v bar from these only min of both will decide what to do
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxh=1;
        int maxb=1; //inital;
        int xurrenth=1;
        int xurrentb=1;
        for(int i=1;i<hBars.size();i++){
            //horizontal will incresae the height and only height will be incresed if it is in a continous manner else its same old stuff
            if(hBars[i]==hBars[i-1]+1){
                // continous one 
                xurrenth++;
            }
            else{
                maxh=max(xurrenth,maxh);
                xurrenth=1;
            }
            
        }
         maxh=max(xurrenth,maxh);
        for(int i=1;i<vBars.size();i++){
            //for breth  same logic copy paste
              if(vBars[i]==vBars[i-1]+1){
                // continous one 
                xurrentb++;
            }
            else{
                maxb=max(xurrentb,maxb);
                xurrentb=1;
            }
        }
         maxb=max(xurrentb,maxb);
        int decider=min(maxh,maxb)+1;
        return decider*decider;
    }
};