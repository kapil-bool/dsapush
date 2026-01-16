class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans=0;
        //all individulas will be there 
        int n=nums.size();
        //n^2 
        for(int i=0;i<n;i++){
            int sum=0;
            unordered_set<int>mp;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                //now check if it is there that is the 
                mp.insert(nums[j]);
                if(mp.count(sum)) ans++;
            }
        }
        
        return ans;
    }
};