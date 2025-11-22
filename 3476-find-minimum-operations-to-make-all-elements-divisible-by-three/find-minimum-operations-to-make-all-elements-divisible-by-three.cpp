class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>possib(3);
        for(int i=0;i<nums.size();i++){
             possib[nums[i]%3]++;
        }
        int ans=0;
        for(int i=1;i<3;i++){
           ans+=possib[i];
        }
        return ans;
    }
};