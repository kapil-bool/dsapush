class Solution {
public:

    void solver(){

    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
    vector<int>prefix(n);
    vector<int>suffix(n);
    prefix[0]=nums[0];
    suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
           prefix[i]=nums[i]*prefix[i-1];
        }
        //suffix one also
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? 1 : prefix[i - 1];        
            int right = (i == n - 1) ? 1 : suffix[i + 1];   
            ans[i] = left * right;
        }
        return ans;
    }
};