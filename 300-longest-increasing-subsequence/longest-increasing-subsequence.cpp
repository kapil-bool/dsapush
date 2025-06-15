class Solution {
public:
    int helper(int index,vector<int>& nums, vector<vector<int>> & dp,int n,int previous){
        //base case
        if(index==n)return 0;
        if(dp[index][previous+1]!=-1)return dp[index][previous+1];

        //now the pick not pick condition
        int not_take=helper(index+1,nums,dp,n,previous)+0;
        int take=0;
        if(previous==-1 || nums[previous]<nums[index])
          take=1+helper(index+1,nums,dp,n,index);
        

        return dp[index][previous+1]=max(take,not_take);
      

    }
    int lengthOfLIS(vector<int>& nums) {
        //a prev will be maintaned here so do the shifting of -1
        int n =nums.size();
        vector<int>current(n+1,0) ,next(n+1,0);
        //prev //and other is index
        for(int index=n-1;index>=0;index--){
            //other changing parameter is the prev
            for(int prev_index=index-1;prev_index>=-1;prev_index--){
                //cordinate shift also done
                int len=next[prev_index+1];
                if(prev_index==-1 || nums[prev_index]<nums[index]){
                    len=max(next[index+1]+1,len);
                }
               current[prev_index+1]=len;
            }
            next=current;
        }
        return next[0];
    }
};

// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     // index: from n-1 to 0
//     for (int index = n - 1; index >= 0; index--) {
//         for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
//             int len = dp[index + 1][prev_index + 1]; // no take
//             if (prev_index == -1 || nums[prev_index] < nums[index]) {
//                 len = max(len, 1 + dp[index + 1][index + 1]); // take
//             }
//             dp[index][prev_index + 1] = len;
//         }
//     }
//     return dp[0][0]; // shifted -1 becomes 0
// }
