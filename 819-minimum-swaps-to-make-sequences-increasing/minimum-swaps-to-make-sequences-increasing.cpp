class Solution {
public:
    int helper(int index,bool swapped,vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
       //base case u reach the end
       if (index==nums1.size()) return 0;
       if(dp[index][swapped]!=-1) return dp[index][swapped];

       int noswapp=1e9;
       int prv_nums1=nums1[index-1];
       int prv_nums2=nums2[index-1];
       if(swapped) swap(prv_nums1, prv_nums2);
       if(nums1[index]>prv_nums1 and nums2[index]>prv_nums2){
          noswapp=helper(index+1,false,nums1,nums2,dp);
       }
       //now the otherpart where u swapp
       int swapp=1e9;
       if(nums1[index]>prv_nums2 and nums2[index]>prv_nums1){
         swapp=1+helper(index+1,true,nums1,nums2,dp);
       }

       return dp[index][swapped]=min(noswapp,swapp);

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //so two condtion are here u make the swap and u dont make the swap
         nums1.insert(nums1.begin(),-1);
         nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); //swap hai so 
       
        return helper(1,false,nums1,nums2,dp);

    }
};