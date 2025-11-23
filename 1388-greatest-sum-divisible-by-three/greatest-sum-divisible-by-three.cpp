class Solution {
public:
     int helper(int index,int mod,int n,vector<int>& nums,vector<vector<int>>&dp){
        //base case u reach the end
        if(index==n){
            //so if u get %3=0 for your current choice make it return else return a samller number 
            return (mod==0)?0:(-1e9);
        }
        if(dp[index][mod]!=-1)return dp[index][mod];
         int take = nums[index] + helper(index + 1, (mod + nums[index]) % 3,n, nums, dp);
        int not_take=helper(index+1,mod,n,nums,dp);

        return dp[index][mod]=max(take,not_take);
    }
    int maxSumDivThree(vector<int>& nums) {
        //basic take not take /see take all the 3 multiplles for sure 
        //repeated sub problem exist 
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));//3 as of 0 1 2 
        return helper(0,0,n,nums,dp);
    }
};
//there can be one more implenttation of taking all the one 
//sort it if mod1 is there in a stack and mode 2 in other stack start ffrom top paring the values from bothh stack and do it till u get the stack empty any one and oviously include the 3 i.e mod 3 