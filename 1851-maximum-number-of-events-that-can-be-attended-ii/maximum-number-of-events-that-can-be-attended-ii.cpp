class Solution {
public:
    //condtion to select is if the curr end< start of next if yes i return the value and add that to the take
   int possible(vector<vector<int>>& events, int currentend , int start){
    int s = start;
    int e = events.size();
    while (s < e) {
        int mid = (s + e) / 2;
        if (events[mid][0] > currentend) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }
    return s; 
}
    int helper(int index,vector<vector<int>>& events,int k,vector<vector<int>> & dp){
        //base case 
        int n=events.size();
        if(k==0 or index==n) return 0;
        if(dp[index][k]!=-1) return dp[index][k];
        //take not take but condtion is like it should not overlap
        int not_take=helper(index+1,events,k,dp);
        //condtion 
        int nextpossible=possible(events,events[index][1],index+1);
        int take= events[index][2] +helper(nextpossible ,events,k-1,dp);
        //certain bvalue must be the value at end

        return dp[index][k]=max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        //so pick not pick is acurate here
        //maximu possible must be found
        sort(events.begin(),events.end());

        return helper(0,events,k,dp);

    }
};