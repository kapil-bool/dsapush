typedef long long ll;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<ll>prefixgcd(n);
        ll maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,1LL*(nums[i]));
            // prefix[i]=maxi;
            //direct gcd will work
            prefixgcd[i]=__gcd(maxi,1LL*nums[i]);
        }

        sort(prefixgcd.begin(),prefixgcd.end());
        //2ptr 
        ll ans=0;
        int left=0;
        int right=n-1;
        while(left<right){
            ans+=__gcd(prefixgcd[left],prefixgcd[right]);
            left++;
            right--;
        }
        return ans;
    }
};