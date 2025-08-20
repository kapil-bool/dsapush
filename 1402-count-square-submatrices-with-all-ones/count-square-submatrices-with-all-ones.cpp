class Solution {
public:
     int n,m;
    int helper(vector<vector<int>> &dp,int index1,int index2,vector<vector<int>>& matrix){
        //so keep the first row and column fix and add it
        //so in the table keep the max and return it 
        //direction ->, down and diagonal (since we are moving forward)
        
        // base case
        if(index1>=n or index2>=m) return 0;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int right=helper(dp,index1,index2+1,matrix);
        int down=helper(dp,index1+1,index2,matrix);
        int diag=helper(dp,index1+1,index2+1,matrix);

        if(matrix[index1][index2]==1){
            dp[index1][index2]=1+min({right,down,diag});
            // maxpossible=max(maxpossible,dp[index1][index2]);
        }
        else{
            //0
            dp[index1][index2]=0;
        }
        
        return dp[index1][index2]; // return local square size, not global max
    }

    int countSquares(vector<vector<int>>& matrix) {
                n=matrix.size();
        m=matrix[0].size();
        // int maxpossible=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(dp,0,0,matrix);
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               total+=dp[i][j];
            }
        }
        return total;
    }
};