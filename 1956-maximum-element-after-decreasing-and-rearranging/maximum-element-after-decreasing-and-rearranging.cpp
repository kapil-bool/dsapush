class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        //can only decrease 
        // condtion <=1;
        sort(arr.begin(),arr.end());
        //check if one is there 
        int n=arr.size();
        int ans=1;
        //make 1 no cost addtion is required 
        for(int i=1;i<n;i++){
            if(arr[i]>=ans+1){
                //condtion is satisfed
                ans++;
                //if not  then i will rearrange
            }

        }
        return ans;
    }
};