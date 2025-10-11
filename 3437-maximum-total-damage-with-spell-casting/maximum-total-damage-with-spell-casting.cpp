class Solution {
public:
    long long helper(int index,vector<int>& unq, unordered_map<int,int> & mp,vector<long long >& dp){
        //base case
        if(index >=unq.size()) return 0;
        //valid 
        if(dp[index]!=-1) return dp[index];
        long long take= 1LL* unq[index]*mp[unq[index]];
        //next one should be >2 the val one 
        int j=index+1;
         while(j<unq.size() and unq[j]<=unq[index]+2){
            j++;
         }
         //u now have a valid one here 
         long long incuded=take+helper(j,unq,mp,dp);
         long long exclude=helper(index+1,unq,mp,dp);

        return dp[index]=max(incuded,exclude);


    }
    long long maximumTotalDamage(vector<int>& power) {
        //here if i take x then all occurnce of x are included in it 
        //make group and in group and the next grp should be x+2> atlest for to be includede 
        //sort them therfore i will be limiting the constrains here also
        unordered_map<int,int>mp;
        for(auto &i: power){
            mp[i]++;
        }
        vector<int>unq;
        for(auto &i:mp){
            unq.push_back(i.first);
        }
        sort(unq.begin(),unq.end());
      vector<long long> dp(unq.size(), -1);
        return helper(0,unq,mp,dp);
    }
};