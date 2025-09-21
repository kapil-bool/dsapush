class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int orr=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if((nums[i]&1)==0){
                orr|=nums[i];
            }
        }
        return orr;
    }
};