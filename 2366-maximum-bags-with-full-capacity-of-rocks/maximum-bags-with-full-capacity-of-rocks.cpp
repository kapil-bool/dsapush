class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //order doesnot matter crete a differ array
        int n=capacity.size();
        vector<int>differ(n);
        for(int i=0;i<n;i++){
            differ[i]=capacity[i]-rocks[i];
        }
        int count=0;
        sort(differ.begin(),differ.end());
        
            for(auto &i:differ){
                if(i==0)  count++;
                else{
                    //see if u can  make it zero by adding the additional one 
                    if(additionalRocks>=i){
                        count++;
                        additionalRocks-=i;
                    }
                    else 
                    break;
                }
            }
        
        return count;
    }
};