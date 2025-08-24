class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       //make a flag true it when 0 and continue it store the lenth of conseutive 1
       // if u encounter any 0 see the flag shrink it till it flag is 0 and then start the expending again
       int right=0;
       int left=0;
       int  flag=0;//for zero
       int ans=0;

       while(right<nums.size()){
           if(nums[right]==0) flag++;

           while (flag > 1) {
                if (nums[left] == 0) flag--;
                left++;
            }

           ans=max(ans,right-left);
           right++;
       }
       return ans;
    }
};