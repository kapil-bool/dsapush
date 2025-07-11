class Solution {
public:
    int helper(int index,int time,vector<int>& satisfaction,  vector<vector<int>> &dp){
        //standear 2 base cases
        if(index==satisfaction.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];
        int nottake=helper(index+1,time,satisfaction,dp);
        int take=0;
        //condtion is each dish is one secondtime+1
        take= satisfaction[index]*(time+1)+helper(index+1,time+1,satisfaction,dp);


        return dp[index][time]=max(take,nottake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value. 
        //because of this statments it is just pick not pick only
        int n=satisfaction.size(); 
       sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,0,satisfaction,dp);

    }
};