class Solution {
public:
   void solver(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> & temp,int start){
     //base case
     if(target==0){
         ans.push_back(temp);
         return;
     }
     for(int i=start;i<candidates.size();i++){
         //2 cases honge 
        //  1. u execede the target only
        if(i>start and candidates[i]>target)break;
        // 2. duplicacy
        if(i>start and candidates[i]==candidates[i-1])continue;
        temp.push_back(candidates[i]);
        solver(candidates,target-candidates[i],ans,temp,i+1);
        temp.pop_back();
     }


   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //backtraking lagaunga
        //unique are neccesary;
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solver(candidates,target,ans,temp,0);
        return ans;

    }
};