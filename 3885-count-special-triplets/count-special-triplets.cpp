class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        //optimal one like take 2 prefix and suffix and approch it like the sliding window
        const long long MOD = 1000000007;
        unordered_map<long long ,long long>right;
        unordered_map<long long ,long long>left;
        for(auto &i:nums){
            right[i]++;
        }
        long long ans=0;
        for(auto &i:nums){
            long long to_ser=i*2;
            right[i]--;
            //count 
            long long leftC=0;
            long long rightC=0;
            leftC+=left[to_ser];
            rightC+=right[to_ser];
            ans=(ans+leftC*rightC)%MOD;
            left[i]++;
        }
        return ans;
    }
};