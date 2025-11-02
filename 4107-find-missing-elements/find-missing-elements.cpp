class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        vector<int> ans;

        int smallest = *min_element(nums.begin(), nums.end());
        int largest  = *max_element(nums.begin(), nums.end());

        for(int i = smallest; i <= largest; i++){
            if(mp.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//n logn 
