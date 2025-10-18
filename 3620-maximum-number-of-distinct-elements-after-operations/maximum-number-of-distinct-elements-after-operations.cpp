class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //sort it and all store in the prev one 
        // keeping the one which have been assigned ?
        int n=nums.size();
        int prev=-1e9;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           //if the prev is x and 
           //the current one is 
           int left_r=nums[i]-k;
           int right_m=nums[i]+k;
           //also the prev 
           int poten=max(prev+1,left_r);
           if(poten<=right_m) {
            ans++;
            prev=poten;
           }
     
        }
        return ans;
    }
};