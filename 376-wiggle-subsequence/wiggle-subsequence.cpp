class Solution {
public:
    int helper(int current ,int prev,int ispos,vector<int>& nums, vector<vector<vector<int>>> &dp){
        if(current==nums.size())return 0;
        if(dp[current][prev][ispos]!=-1) return dp[current][prev][ispos];
        //not take and take condtion here 
        int take=0;
        if((ispos and nums[current]<nums[prev])  ||( !ispos and nums[current]>nums[prev])){
            take=1+helper(current+1,current,!ispos,nums,dp);
        }

        int nottake=helper(current+1,prev,ispos,nums,dp);

        return dp[current][prev][ispos]=max(take,nottake);

    }
    int wiggleMaxLength(vector<int>& nums) {
        //wigglet +1
        //so here it is pick and not pick and then the max of it //dp for sure as repete sub problem are there

//but u also need to keep the track of previous one also        int n=nums.size();
int n=nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        //now here there will be two time calll of the function
        return max(helper(1,0,true,nums,dp),helper(1,0,false,nums,dp))+1;
    }
};