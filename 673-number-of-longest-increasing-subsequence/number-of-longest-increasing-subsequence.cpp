class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
               if(nums[prev]<nums[i] and dp[i]< dp[prev]+1){
                 dp[i]=1+dp[prev];
                 count[i]=count[prev]; //only one is here 
               }
               //one will be u  u are getting equal
              else  if(dp[i]==dp[prev]+1){
                count[i]+=count[prev];
               }
            }

            //now the max elem and its count from the count
        }
            int max_elem=*max_element(dp.begin(),dp.end());
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(dp[i]==max_elem){
                    cnt+=count[i];
                }
            }

        
        return cnt;
    }
};