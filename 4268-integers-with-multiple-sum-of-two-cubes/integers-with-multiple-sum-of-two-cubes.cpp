class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        //brute force??
        vector<int>ans;
        unordered_map<int,int>mp;
        int limit_it=cbrt(n);
        for(int a=1;a<=limit_it;a++){
             long long a3=1LL*a*a*a;
             for(int  b=a;b<=limit_it;b++){
              long long b3=1LL*b*b*b;
               long long sum=1LL*(a3+b3);
                //if it is more no need to check;
                if(sum>n) break;
                 mp[sum]++;

             }

        }
        for(auto &i:mp){
            int it=i.second;
            if(it>=2){
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};