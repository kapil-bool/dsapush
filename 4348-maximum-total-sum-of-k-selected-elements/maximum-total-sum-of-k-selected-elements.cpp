typedef long long ll;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        //first i want to do mul 
        sort(nums.rbegin(),nums.rend());
        for(auto &i:nums) cout<<i<<" ";
        ll first=min(k,mul);
        ll ans=0;
        for(int i=0;i<k;i++){
            if(first){
                ans += (long long)nums[i] * mul;
                first--;
                mul--;
            }
            else{
                ans+=nums[i];
            }
        }
        return ans;
    }
};