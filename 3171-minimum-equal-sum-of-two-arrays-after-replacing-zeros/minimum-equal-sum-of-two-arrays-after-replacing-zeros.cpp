class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0,zeroes1=0,zeroes2=0;
        //count them 
        for(auto i:nums1){
            sum1+=i;
             if (i == 0) {
                sum1++;
                zeroes1++;
            }
        }
        for(auto i:nums2){
            sum2+=i;
           if (i == 0) {
                sum2++;
                zeroes2++;
            }
        }

        //now will be min and other willbe max //take the max one
        long long toachive=max(sum1,sum2);
        //now handel the -1 case also;
          if (!zeroes1 && sum2 > sum1 || !zeroes2 && sum1 > sum2) {
            return -1;
        }
        
        return toachive;
    }
};