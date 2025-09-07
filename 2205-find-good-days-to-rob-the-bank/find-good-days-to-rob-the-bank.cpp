class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        //so if u look at the first one it say atleast time days before the roberey as it says k=2 start from 2 and check 
        //that the only significance of condtion 1 
        //condtion2->before should 4 1 0 like this this means the start should be gretes and decrease till i one here
        vector<int>noninc(n,0);
        vector<int>nondec(n,0);
        vector<int>ans; //push khelunga yaha par to
        for(int i=1;i<n;i++){
            //already start with one
            if(security[i]<=security[i-1]) noninc[i]+=noninc[i-1]+1;
            else{
                continue; //as already 0 fill hai 
            }
        }
        for(int i=n-2;i>=0;i--){
            //already start with one
              if(security[i]<=security[i+1]) nondec[i]+=nondec[i+1]+1;
            else{
                continue; //as already 0 fill hai 
            }
        }
        //now the answewr one
        for(int i=time;i<=n-1-time;i++){
              if(noninc[i]>=time and nondec[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};