class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int> ans(nums.size());
       //insertion of values !=pivot handeling
       int sm=0;
       int big=nums.size()-1;
       for(int i=0,j=nums.size()-1;i<nums.size();i++,j--){
         if(nums[i]<pivot){
            //smaller hai iska matlab
            ans[sm]=nums[i];
            sm++;
         }
          if( nums[j]>pivot){
            ans[big]=nums[j];
            big--;
         }
       }
       while(sm<=big){
         //smaller and bigger wont mve in this cases 
         //therfore they are pivot
        //  insert them nec=xt to the smalee one in ans arr
        ans[sm]=pivot;
        sm++;
       }
       return ans;
    }
};
/*
same approch as  put the zeroes first then trhe second and then the remaing can be put 0 
here 1===pivot
2>pivo
1><pivot*/