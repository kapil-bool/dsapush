class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        long long pairs=0;
        int left=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int right=0;right<n;right++){
            //apply the condition
            //must be more than then k;
            pairs+=mp[nums[right]];
            mp[nums[right]]++;
            while(pairs>=k){
                //one valid is found;
                ans+=n-right;
                mp[nums[left]]--;
                pairs-=mp[nums[left]];
                left++;
            }

        }
        
        return ans;
    }
};