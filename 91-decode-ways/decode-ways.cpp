class Solution {
public:
    int helper(int index,string s,vector<int>& dp){
        //base case and 0 
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) return dp[index];

        int ways=helper(index+1,s,dp);
        //now se if they can be decoded as 2 like 26 as 2 and 6 and 26 also so 
        if(index+1<s.size()){
            //change into number using stoi
             int num = (s[index] - '0') * 10 + (s[index + 1] - '0');
             if(num>=10 and num<=26){
                //then call the helper again
                ways+=helper(index+2,s,dp);
             }
        }

        return dp[index]=ways;

    }
    int numDecodings(string s) {
        //so how do i decode this
        //everything in terms of index only one needed here 
        int n=s.size();
        vector<int>dp(n,-1);
        // overlaping to hai like 226  it have repeating subproblems
        return helper(0,s,dp);
    }
};