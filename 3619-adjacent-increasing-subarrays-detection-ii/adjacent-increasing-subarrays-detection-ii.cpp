class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        //so if there is just a singlr one then i can do like /2 at end 
        //but if there is a change chen i have to check that 
        //switch here 
        int prevl=0;
        int ans=0;
        int n=nums.size();
        int count=1; //itself will be there
        for(int i=1;i<n;i++){
          if(nums[i]>nums[i-1]) count++;
          else{
             //this means there is a change 
             /* 1.store the current count and reset it*/
             prevl=count;
             count=1;
             //now when ever ther is a change in 
          }
          //storing is there and u got it
          ans=max(ans,min(prevl,count));
          ans=max(ans,count/2);
        }
           return ans;
    }
};