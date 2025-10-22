class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        //maintan both negative and positive count and if both are equal return it else -1 
        if(k==0){
            return nums1==nums2 ?0 : -1;
        }
        long long pos=0;
        long long neg=0;
        for(long long i=0;i<nums1.size();i++){
            long long differ=nums1[i]-nums2[i];
            //possible or not if  not return -1 at that insted only else 
            if(differ %k !=0) return -1;
            //else 
            long long ope=differ/k;
            if(ope>0) pos+=ope;
            else
            neg+=ope;
        }
      if(pos==(-neg)) return pos;
      return -1;
    }
};