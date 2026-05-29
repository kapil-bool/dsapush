class Solution {
public:
    int minElement(vector<int>& nums) {
       int mini=1e9;
       int n=nums.size();
       for(int i=0;i<n;i++){
            int number=nums[i];
            int sum=0;
            while(number){
                sum+=number%10;
                number/=10;
            }
            mini=min(mini,sum);
       }
       return mini;
    }
};