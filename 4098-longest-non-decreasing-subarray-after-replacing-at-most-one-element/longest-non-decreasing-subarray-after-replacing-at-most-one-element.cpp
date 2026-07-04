class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //it need length thats it and only one is replaceable ;
        //idea is from current index till wher i have a increasing sequence right
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                prefix[i]=prefix[i-1]+1;
            }
            else{
                prefix[i]=1;
            }
        }
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i]=1;
            }
        }
        int ans=1;
        for(auto&i:prefix){
            ans=max(ans,i);
        }
        //take left or right or merge accordingly this can be the answer here ;
        for(int i=0;i<n;i++){
            //for the 0 index only pre matter
            //for the last only suff matter other wise look for an intersection
            if(i>0){
                ans=max(ans,prefix[i-1]+1);
            }
            if(i+1<n){
                ans=max(ans,suffix[i+1]+1);
                //considering myself to be the one 
            }
            if(i>0 and i+1<n and nums[i-1]<=nums[i+1]){
                //got a middle one ;
                ans=max(ans,suffix[i+1]+prefix[i-1]+1);
            }
        }
       return min(n,ans);
    }
};