class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end()); 
        vector<int> ans(nums2.size());
        //if found a biiger one in the nums 1 add it to ans else add the smallest one there 
        //if found a bigger j'ust bigger use it else saller one and erase it once used
        for (int i = 0; i < nums2.size(); i++) {
           
            auto it = s.upper_bound(nums2[i]);

            if (it == s.end()) {
               
                it = s.begin();
            }

            ans[i] = *it;
            s.erase(it); // remove from available 
        }

        return ans;
    }
};

