class Solution {
public:
void helper(vector<int>& nums,vector<int>& store, vector<vector<int>>&ans,int n,vector<bool>&used){
    //base case
    if(store.size()==n){
        ans.push_back(store);
    }

    for(int i=0;i<n;i++){
        if(used[i])continue;
        if(i>0 and  nums[i]==nums[i-1] and !used[i-1])continue; 

        used[i]=1;
        store.push_back(nums[i]);
        helper(nums,store,ans,n,used);
        //backtarack
        store.pop_back();
        used[i]=0;

    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>store;
        vector<vector<int>>ans;
        int n=nums.size();
        vector<bool>used(n,0);
        sort(nums.begin(),nums.end());
        helper(nums,store,ans,n,used);
        return ans;
    }
};