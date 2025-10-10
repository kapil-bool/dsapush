class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        //previous one pe dependent hai so use dp from back or just preffix;
        int n=energy.size();
        vector<int>dp(n,0);
        for(int i=n-1;i>=0;i--){
            if(i+k<n){
                //exist karta hai still
                dp[i]=dp[i+k]+energy[i];
            }
            else{
                //just add the energyindex 
                dp[i]=energy[i];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};