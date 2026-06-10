typedef long long ll;
class Solution {
public:
    vector<ll>dp;
    int n;
    ll helper(int index,vector<int>& nums, vector<int>& colors){
        if(index >=n) return 0;
        if(dp[index]!=-1)  return dp[index];
        ll ans=0;
        if(index==n-1){
            return dp[index]=nums[index];
        }
        if(colors[index]==colors[index+1]){
            //botha are the possibltes here pick one 
            //make recursive call here;
            ans=max(nums[index]+helper(index+2,nums,colors),helper(index+1,nums,colors));
        }
        else{
            //u pick for sure here
            ans=nums[index]+helper(index+1,nums,colors);
        }
        return dp[index]=ans;
        
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        n=nums.size();
        dp.assign(n+5,-1);
        return helper(0,nums,colors);
    }
};