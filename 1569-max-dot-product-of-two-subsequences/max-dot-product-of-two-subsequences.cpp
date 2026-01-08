class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    //here already exist wali condtion use hoto saki hai as unique hai mentioed 
    int helper(int i,int j,vector<int>& nums1, vector<int>& nums2){
    if(i==n || j==m) return -1e9;
    if(dp[i][j]!=-1e9) return dp[i][j];
    int take_both=nums1[i]*nums2[j]+max(0,helper(i+1,j+1,nums1,nums2));
    int b_i=helper(i+1,j,nums1,nums2);
    int b_j=helper(i,j+1,nums1,nums2);
     
     dp[i][j]=max({take_both,b_i,b_j});
     
     return dp[i][j];

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        //3 cases i j bot picked searched for beeter i or better j
        //solve accordingly
        n = nums1.size();
        m = nums2.size();
        // dp.assign(n, vector<int>(m, NEG_INF));
       
        dp.assign(n,vector<int>(m,-1e9));
        return helper(0,0,nums1,nums2);
        //that it i guess;

    }
};