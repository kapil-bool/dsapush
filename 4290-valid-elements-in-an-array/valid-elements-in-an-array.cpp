class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>a;
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
              if(i == 0 || i == n-1){
                a.push_back(nums[i]);
            }
            else{
                if(nums[i] > prefix[i-1] || nums[i] > suffix[i+1]){
                    a.push_back(nums[i]);
                }
        }
    }
        return a;
    }
};