class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=1e9;
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++){
            int curr=arr[i]-arr[i-1];
            if(curr<mini){
               ans.clear();
               ans.push_back({arr[i-1],arr[i]});
               mini=min(curr,mini);
            }
            //also equal 
            else if(curr==mini){
               ans.push_back({arr[i-1],arr[i]});
                // ans.push_back({})
            }
        }
        return ans;
    }
};