class Solution {
public:
vector<vector<int>>ans;
 vector<vector<int>>helper(int k,int n,int index,vector<int>&temp){
    //return kab hoga u reach the sum and the size of your current temp is ==n if not both then just return and atmost one so always index+1;
    if(temp.size()==k and n==0){
        ans.push_back(temp);
        return {};
    }
    //now return when
    if(temp.size()>k or n<0){
        return {};
    }
    for(int i=index;i<=9;i++){
        temp.push_back(i);
        helper(k,n-i,i+1,temp);
        temp.pop_back();
    }
    return ans;

 }
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>temp;
        return helper(k,n,1,temp);
    }
};