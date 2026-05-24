class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        //k times 
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        vector<int>ans;
            
        for(auto &i:mp){
            int cnt=1e9;
            int cntfornumber=i.second;
            int number=i.first;
            int printer=min(cntfornumber,k);
            for(int i=0;i<printer;i++){
                ans.push_back(number);
            }

        }
        return ans;
    }
};