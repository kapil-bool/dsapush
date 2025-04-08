class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //back simulation is quite good here
        unordered_set<int>seen;
        int n=nums.size();
        int count=0;
        for(int i=n-1;i>=0;i--){
        //    if u see it remove the 3 elements from start
         if (seen.count(nums[i])) {
                return (i + 3) / 3; 
            }
            seen.insert(nums[i]);
        }
       
        return 0;
    }
};