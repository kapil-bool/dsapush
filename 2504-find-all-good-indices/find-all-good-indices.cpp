class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        //backward as well the front input are here on which it depend so accordinly
        //prfx and sufx one
        //like maintain the order and count like struture and make it zero if not satisied 
        // i have done something like this before ig
        //rob bankmone change the few condtion and good to go
           int n=nums.size();
        //so if u look at the first one it say atleast time days before the roberey as it says k=2 start from 2 and check 
        //that the only significance of condtion 1 
        //condtion2->before should 4 1 0 like this this means the start should be gretes and decrease till i one here
        vector<int>noninc(n,1);
        vector<int>nondec(n,1);
        vector<int>ans; //push khelunga yaha par to
        for(int i=1;i<n;i++){
            //already start with one
            if(nums[i]<=nums[i-1]) noninc[i] = noninc[i - 1] + 1;
            else{
                continue; //as already 0 fill hai 
            }
        }
        for(int i=n-2;i>=0;i--){
            //already start with one
              if(nums[i]<=nums[i+1]) nondec[i] = nondec[i + 1] + 1;
            else{
                continue; //as already 0 fill hai 
            }
        }
        //now the answewr one
        for(int i=k;i<=n-1-k;i++){
              if(noninc[i-1]>=k and nondec[i+1]>=k) ans.push_back(i);
        }
        return ans;
        
    }
};