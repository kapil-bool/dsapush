class Solution {
public:
    vector<vector<vector<int>>>dp;
    vector<vector<int>>grid;
    int m, n;
    int helper(int index1, int index2,int k){
        //boundary
        if(index1>=m or index2>=n){
            return -1e9;
        }
        if(dp[index1][index2][k]!=-1) return dp[index1][index2][k];
        int cost=(grid[index1][index2]==0 ?0:1);
        if(cost>k){
            //prun itl
            return -1e9;
        }
        if(index1==m-1 and index2==n-1){
            return dp[index1][index2][k] = grid[index1][index2];
        }
        int down=helper(index1+1,index2,k-cost);
        int right=helper(index1,index2+1,k-cost);
        int best=max(down,right);
        if(best==(-1e9)){
            return dp[index1][index2][k]=-1e9;
            //this wont be explored 
        }
         
         return dp[index1][index2][k]=best+grid[index1][index2];

    }
    int maxPathScore(vector<vector<int>>& g, int k) {
        grid=g;
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(k + 1, -1)));
        int ans=helper(0,0,k);
        return (ans < 0 ? -1 : ans);
    }
};