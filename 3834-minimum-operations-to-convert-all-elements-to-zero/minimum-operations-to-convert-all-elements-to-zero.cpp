class Solution {
public:
    int minOperations(vector<int>& nums) {
        //here find the minimu elemt longest subaaray any possible 
        //partion will be 0 here 
        //if a zero is there make the smallest one marking operation 1 till here now move forwrd again 
        vector<int>stack;
        int ans=0;
        for(int a:nums){
            while(!stack.empty() and stack.back()>a){
                //min elem is founded 
                stack.pop_back();
            }
            if(a==0) continue;
            if(stack.empty() or stack.back()<a){
                ans++;
                stack.emplace_back(a);
            }
        }
        return ans;
    } 
};