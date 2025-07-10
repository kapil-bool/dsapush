class Solution {
public:
    int helper(int current,int previous,vector<vector<int>>& dp, vector<pair<int,int>>&consider){
        if(current==consider.size()) return 0;
        if(dp[current][previous+1]!=-1) return dp[current][previous+1];
        int nottake=helper(current+1,previous,dp,consider);
        int take=0;
        //one for the previos and the other for the age condtion
        if(previous==-1 or consider[current].second>= consider[previous].second){
            take=consider[current].second+helper(current+1,current,dp,consider);
        }
        return dp[current][previous+1]=max(take,nottake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //A conflict does not occur between players of the same age.
        //here create the array and store that in order
        vector<pair<int,int>>consider;
        for(int i=0;i<ages.size();i++){
             consider.push_back({ages[i], scores[i]});
        }
        sort(consider.begin(),consider.end());
        int n=consider.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return helper(0,-1,dp,consider);

    }
};