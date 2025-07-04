class Solution {
public:
    vector<int>dp;
    int helper(int index,vector<int>& stoneValue,int n){
        //base case
        if(index==n) return 0;
        if(dp[index]!=-1e9) return dp[index];
        // so maintain the possible sum for alice and return it if +ve print alice =0 then tie and -Ve bob
        // so not more than 3 also 
        int sum=0;
        int differ=-1e9;
        for(int i=0;i<3 and i+index<n ;i++){
            sum+=stoneValue[i+index];
            //now the bob possiblities
            //now minus it from all the 3 possible picks of other players
            differ=max(differ,sum-helper(i+1+index,stoneValue,n));
        }
        return dp[index]=differ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        //all possible ways will be tried 
        //so i have 3 option in pick also  but it cant be implemted like that for sure like 3 indexed i mantain an pass in 
        //the dp hmmm
        int n=stoneValue.size();
        dp = vector<int>(n, -1e9);
         int verdict=helper(0,stoneValue,n);
         if(verdict==0){
            return "Tie";
         }
         else if(verdict >0)  return "Alice";
         else
          return "Bob";
    }
};