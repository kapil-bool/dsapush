class Solution {
public:
    static bool compare(string &a ,string &b){
        return a.size()<b.size();
        //a will always be the bigger one
    }

    bool cheker(string &a, string &b){
        if(a.size()!=b.size()+1)return false;
        bool allowed=false; //only one skip
        int i=0,j=0;
        while(i<a.size() and j<b.size()){
            if(a[i]==b[j]){
                i++,j++;
            }
            else{
                if(allowed) return false;
                allowed=true;
                i++; 
                
            }
        }
        return true;

    }

    int longestStrChain(vector<string>& words) {
        //lis stragegy lagunga will nedd to compare  two string and only one skip should be alowed 
        sort(words.begin(),words.end() , compare);
        int n=words.size();
        vector<int>dp(n,1); //filling will be on the bases of cheker function;
        int maxi=1;
        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(cheker(words[i],words[prev]) ){
                    dp[i]=max(1+dp[prev],dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        
        }

        return maxi;
    }
};