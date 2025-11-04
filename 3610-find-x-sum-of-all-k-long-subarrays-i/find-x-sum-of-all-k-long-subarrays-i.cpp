class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        //window of size k and top x elem add them and return 
        //brute force as u cant solve it 
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<k+i;j++){

                //fill the map
                mp[nums[j]]++;
            }
          vector<pair<int,int>>freq;
          for(const auto &[key,value]:mp){
             freq.push_back({value,key});
          }
          //here comparator also needed
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());
        int tempsum=0;
        //now access this freq one and add them
        //atlest 2 should be there
        for(int j=0;j<x && j<freq.size();j++){
            tempsum+=freq[j].first* freq[j].second;
        }
        ans.push_back(tempsum);
        }

        return ans;

    }
};