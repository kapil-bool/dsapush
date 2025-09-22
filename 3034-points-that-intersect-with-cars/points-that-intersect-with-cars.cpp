class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        //here manage the overlap i.e take them only once 
        sort(nums.begin(),nums.end());
        //now manage the start and end overlaping
        int ans=0;
        int start=nums[0][0];
        int end=nums[0][1];
        for(int i=1;i<nums.size();i++){
            //
            if(nums[i][0]<=end){
                //this is extension of interval
                end=max(end,nums[i][1]);
            }
            else{
                //this means a new interval is found change the s and end
                ans+=(end-start+1);
                start=nums[i][0];     
                end=nums[i][1];       
            }
        }
        //last wale ko explectly check karna hoga as there are no more in front of it 
        ans+=end-start+1;
        return ans;
    }
};