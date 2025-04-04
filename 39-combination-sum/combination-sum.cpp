class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index,int target,vector<int> &candidates,vector<int> &temp){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(temp); //this means it reach the target therfore push it into the temp arr
            }
                return; //perfect 
        }
        if(candidates[index]<=target){
            //left recursion and then right recursion
            temp.push_back(candidates[index]);
            helper(index,target-candidates[index],candidates,temp);
            //u reched the end but still target is not achieved;
            temp.pop_back();
        }
        helper(index+1,target,candidates,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp; //to store the combinations
        helper(0,target,candidates,temp);
        return ans;
        
    }
};