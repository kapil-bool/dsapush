class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int  ans=-1;
        // int index=-1;
        int current= 1e9;
        for(int i=0;i<capacity.size();i++){
          if(capacity[i]>=itemSize  and capacity[i]<current){
            //possib
             ans=i;
             current=capacity[i];
          }
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};