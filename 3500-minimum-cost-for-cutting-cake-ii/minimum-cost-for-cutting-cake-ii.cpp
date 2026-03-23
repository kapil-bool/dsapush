class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        //with each cut i will be encuring the cost of other one 
        //i think in order perform karna better hai highest then the next one ans so on till alll are seprated;
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());
        int i=0;
        int j=0;
        long long hoript=1;
        long long vertipt=1;
        int sizn=verticalCut.size();
        int sizm=horizontalCut.size();
        long long ans=0;
        while(i<sizm and j<sizn){
           if(horizontalCut[i]>verticalCut[j]){
                 //here u make the cut and add the cost;
                 ans+=horizontalCut[i]* vertipt;
                 i++;
                 hoript++;
           }
           else{
                 //here u make the cut and add the cost;
                 ans+=verticalCut[j]*hoript;
                 j++;
                 vertipt++;
           }
        }

        //now remaing cuts 
        while(i<sizm){
              ans+=horizontalCut[i]* vertipt;
                 i++;
                //  hoript++;
        }
        while(j<sizn){
             ans+=verticalCut[j]*hoript;
                 j++;
                //  vertipt++;
        }

        return ans;
    }
};