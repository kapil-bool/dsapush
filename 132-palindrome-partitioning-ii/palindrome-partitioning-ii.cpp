class Solution {
public:
    bool is_palindrome(int i,int j ,string &s){
        //check for palindrom here
        //j is the partion here -> k so j-- i++
        while(i<j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else
            return false;
        }
        return true;
        //perfecto
    }
    int helper(int i,int j,string &s,vector<int>&dp){
       if (i == s.size()) return 0; 
       if(dp[i]!=-1) return dp[i];
        int mini=1e9;
        //here also incoprate the palindrom condition if satisy then procedu;
        for(int k=i;k<=j;k++){
            if(is_palindrome(i,k,s)){
            int cuts=1+helper(k+1,j,s,dp);
            mini=min(mini,cuts);
            }
        }
        return dp[i]=mini;
        // return mini;

    }
    int minCut(string s) {
       //so for sure need to see if palindrom or not cretae a bool finction for this 
       //and the bascix helper one
       //front partion is the comncept here
       int n=s.size();
       vector<int>dp(n,-1);//only one changing variable
       return helper(0,n,s,dp)-1; //-1 as last cut is off no use
    }
};