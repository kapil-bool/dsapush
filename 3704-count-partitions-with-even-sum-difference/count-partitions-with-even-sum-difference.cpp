class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int leftsum=0;
        for(int i=0;i<nums.size()-1;i++){
          int rightsum=0;
            leftsum=nums[i];
            rightsum=sum-leftsum;
            if((rightsum-leftsum)%2==0)count++;
        }
        return count;
    }
};