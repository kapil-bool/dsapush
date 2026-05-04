typedef long long ll;
class Solution {
public:
    vector<int > minCost(vector<int>& nums, vector<vector<int>>& queries) {
        //lets go 
        int n=nums.size();
        // vector<int>a(n);
        //closed //prefix suffix 
        //checking at each point if adj then okay +1 else apply the prefix and suffix operation
        vector<ll>prefix(n,0);
        vector<ll>suffix(n,0);
       
        for(ll i=0;i<n-1;i++){
            //logic is +1 or the abs to  check here 
            ll to_r=nums[i+1]-nums[i];
            ll to_l=(i>0)?(nums[i]-nums[i-1]):LLONG_MAX;
            prefix[i+1]=prefix[i]+(to_r<to_l  ?1: (to_r));
        }
        for(ll i=n-1;i>0;i--){
            //logic is +1 or the abs to  check here 
           ll to_l=nums[i]-nums[i-1];
           ll to_r=(i<n-1)?(nums[i+1]-nums[i]):LLONG_MAX;
          suffix[i-1] = suffix[i] + (to_l <= to_r ? 1 : ( to_l));
        }
         ll ql=queries.size();
         vector<int>a(ql);
        for(ll i=0;i<ql;i++){
            ll l=queries[i][0];
            ll r=queries[i][1];
            if(l<=r){
                //prefix use hoga here ;
                //running sum here with an comparison but  difficult to oncoparte so better the condtion of add 1 or the abs differnce take directly
               a[i]=(int)prefix[r]-prefix[l];
            }
            else{
               a[i]=(int)suffix[r]-suffix[l];

            }
        }
        return a;
    }
};