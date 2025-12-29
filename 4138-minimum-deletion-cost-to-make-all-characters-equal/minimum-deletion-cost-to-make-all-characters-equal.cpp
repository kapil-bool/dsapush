class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        //total cost 
        //a->x same like this if only x is there then u got it what if b is left u got 
        //fractional knapsack jese hai
        vector<long long>store(26,0);
        long long totalcost=0;
        for(long long i=0;i<s.size();i++){
            totalcost+=cost[i];
            store[s[i]-'a']+=cost[i];
        }
        long long current= LLONG_MAX;
        for(long long i=0;i<26;i++){
            if((totalcost-store[i])>current) continue;
            else
             current=(totalcost-store[i]);
        }
        return current;
    }
};