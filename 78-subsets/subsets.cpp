class Solution {
public:
    vector<vector<int>>ans;
    
    void helper(int index,vector<int>& nums,vector<int>& temp){
        
         ans.push_back(temp);
        
        //to chases u want to tkae and u dont want to take it 
        for(int i=index;i<nums.size();i++){
           //take one
           temp.push_back(nums[i]);
           helper(i+1,nums,temp);
           temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //so if u see all its like pick and not pick here
        //any order is mentioned so not a problem
        vector<int>temp;
        helper(0,nums,temp);
        return ans;
    }
};