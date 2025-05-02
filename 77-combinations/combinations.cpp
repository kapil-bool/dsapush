class Solution {
public:
 void helper(int n,int k, vector<vector<int>> & ans,vector<int> &store,int start){

    //base case
    if(store.size()==k){
        ans.push_back(store);
        return;
    }
    for(int i=start;i<=n;i++){
        //store bhi to hoga and pop back bhi hoga
        store.push_back(i);
        helper(n,k,ans,store,i+1);
        store.pop_back();
    }

}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>store;
        helper(n,k,ans,store,1);
        return ans;
    }
};