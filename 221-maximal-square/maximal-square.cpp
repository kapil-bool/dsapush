class Solution {
public:
    int n,m;
    int helper(vector<vector<int>> &dp,int index1,int index2,int & maxpossible,vector<vector<char>>& matrix){
        //so keep the first row and column fix and add it
        //so in the table keep the max and return it 
        //direction ->, down and diagonal (since we are moving forward)
        
        // base case
        if(index1>=n or index2>=m) return 0;

        if(dp[index1][index2]!=-1) return dp[index1][index2];

        int right=helper(dp,index1,index2+1,maxpossible,matrix);
        int down=helper(dp,index1+1,index2,maxpossible,matrix);
        int diag=helper(dp,index1+1,index2+1,maxpossible,matrix);

        if(matrix[index1][index2]=='1'){
            dp[index1][index2]=1+min({right,down,diag});
            maxpossible=max(maxpossible,dp[index1][index2]);
        }
        else{
            //0
            dp[index1][index2]=0;
        }
        
        return dp[index1][index2]; // return local square size, not global max
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        //ok i got it now will code in piece now 
        //solved
        //see direction are needed here so if u have to fix two of the sides and design direction according to that only
        n=matrix.size();
        m=matrix[0].size();
        int maxpossible=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(dp,0,0,maxpossible,matrix);
        return maxpossible*maxpossible;
    }
};
