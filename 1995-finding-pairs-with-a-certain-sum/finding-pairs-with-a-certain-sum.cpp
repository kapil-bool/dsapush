class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums1) {
            freq1[num]++;
        }
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto& [num, cnt] : freq1) {
            //so travling the fre1 map and then founding the adjucent value from anither map and return the multiple
            ans += cnt * freq2[tot - num];
        }
        return ans;
    }
};