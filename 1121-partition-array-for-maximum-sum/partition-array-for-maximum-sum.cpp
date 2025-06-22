class Solution {
public:
    int helper(int i, int n,vector<int>&arr,int k,vector<int>& dp){
        //base case
        //mak of martion and the sum which can be calulted using the lenght
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int max_value=0; 
        int sum=0;
        for(int j=i;j<min(n,(i+k));j++){
           max_value=max(max_value,arr[j]);//already possiblites search karta ayega woo so 
           int lenght=j-i+1;
           int currentsum=(lenght*max_value)+helper(j+1,n,arr,k,dp);
           sum=max(sum,currentsum);
        }
       return dp[i]= sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(0,n,arr,k,dp);
    }
};