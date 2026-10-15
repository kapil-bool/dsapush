class Solution {
public:
    int sumCounts(vector<int>& nums) {
        //100 bf
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>st;;
            for(int j=i;j<n;j++){
               st.insert(nums[j]);
                // for(auto&i:st){
                   ans+=st.size()*st.size();
                   cout<<i<<" ";
                // }
                
            }
            st.clear();
        }
        return ans;
    }
};