class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //at lest k times
        //pehla complete le jaa
        // uske baaad shrinkage chalu kar le
        long long right=0;
        long long left=0;
        long long maxelem=*max_element(nums.begin(),nums.end());
        long long count=0;
         long long ans=0;
        while(right<nums.size()){
            //element found is max elemement but not enough to form k;
            if(nums[right]==maxelem){
                count++;
            }
           
            while(count>=k){
                // left wala hoga usko check karo
                //ans bhi callulate kar lr 
                //jaha par ho gayi hai condition uske end tak ko ek he manunga
                ans+=(nums.size()-right);
                if( nums[left]==maxelem)         
                count--;
                left++;
            }
            right++;


        }
        return ans;
    }
};