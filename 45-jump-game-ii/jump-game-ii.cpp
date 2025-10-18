class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;           
        int current = 0;        
        int max_reachable = 0;   

        for(int i = 0; i < n - 1; i++) {
            
            max_reachable = max(max_reachable, i + nums[i]);

        
            if(i == current) {
                count++;
                current = max_reachable;
            }
        }

        return count;
    }
};
