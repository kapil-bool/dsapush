class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //ok lets decode it 
        //oo so the sum must be less than uppper range and more than the lower one i get it now 
        // 1 <= nums.length <= 105 so this may be a problem
        //use prefix and suffix here 
        multiset<long long> prefixSums; //allow duplicates that it 
        long long sum = 0;
        int count = 0;
        prefixSums.insert(0);
        for(int i=0;i<nums.size();i++){
            //insert it 
            sum+=nums[i];
            //range as well as indivdual can be the answer 
            //so check  for the sum as range and also for itself also //so this will be enough ig
            //multiple will be there 0 to 3 all valid 0 1 2 3 all indival and grop of 2 3 and whole also
            auto left = prefixSums.lower_bound(sum - upper);
            auto right = prefixSums.upper_bound(sum - lower);

            count += distance(left, right);

            // Insert current prefix sum for future iterations
            prefixSums.insert(sum);
        }

        return count;
    }
};