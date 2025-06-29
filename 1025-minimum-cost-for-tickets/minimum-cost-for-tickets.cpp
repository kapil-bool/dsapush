class Solution {
public:
    int helper(int index,vector<int>& days, vector<int>& costs,int n,vector<int> &dp){
        if(index==days.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int mini=1e9;
        //i will have option on each day that of exaatution that what ccan u chose
        //cost 0;
        int one_day=costs[0]+helper(index+1,days,costs,n,dp);
        int i=index;
        while(i<n and days[i]<days[index]+7)i++; //here only the i is moved
        int seven_day=costs[1]+helper(i,days,costs,n,dp);
         i=index;
        while(i<n and days[i]<days[index]+30)i++; //here only the i is moved
        int thirty_day=costs[2]+helper(i,days,costs,n,dp);
         
        mini=min({one_day,seven_day,thirty_day});
        dp[index]=mini;
        return dp[index];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,-1);
        return helper(0,days,costs,n,dp);
    }
};