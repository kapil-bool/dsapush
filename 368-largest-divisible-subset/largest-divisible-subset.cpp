class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>reconstruct;
        int n= nums.size();
        int maxi=1;
        int lastindex=0;
        vector<int>dp(n,1),hash(n);
        //now just fill this 
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                //changing condition kya hoti hai for hash that dp[prev]+1 >dp[i]
               if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i]=1+dp[prev];
                    hash[i]=prev; //store the index
                }
               if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
               }
            }
        }
            //now the printing algo
            vector<int>result; //only hash array and nums array will be needed u push the elemnt nums[index] and 
            result.push_back(nums[lastindex]);
            while(hash[lastindex]!=lastindex){
                lastindex=hash[lastindex];
                result.push_back(nums[lastindex]);

            }
            reverse(result.begin(),result.end());

        return result;
    }
};