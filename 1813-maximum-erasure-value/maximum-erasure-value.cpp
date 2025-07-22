class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int total=0,left=0;
        unordered_map<int,int>freq;
       
        int n=nums.size();
        for(int i=0;i<n;i++){
             freq[nums[i]]++; 
             sum+=nums[i];
             //check if its unique or not
             while(freq[nums[i]]>1){
                //no more a unique element
                // remove it from the sum
                freq[nums[left]]--;
                sum-=nums[left];
                left++;
             }
             total=max(sum,total);
        }
        return total;
    }
};