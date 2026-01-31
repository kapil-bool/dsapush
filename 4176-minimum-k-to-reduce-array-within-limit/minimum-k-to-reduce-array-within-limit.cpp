class Solution {
public:
    int used(vector<int>& nums , int k){
        //here 
        int answer=0;
        for(int i=0;i<nums.size();i++){
            int div=nums[i];
            int operation= (div+k-1)/k;
            answer+=operation;
        }
        return answer;

    }
    int binarys(int upper,int lower,vector<int>&nums){
        //reminder 0 if more negative its a plus point for me 
        int answer=upper;
        while(upper>=lower){
        int mid=(lower+upper)/2;

        if(used(nums,mid)<=(1LL* mid*mid)){
            //here find a smller one 
            answer=mid;
            upper=mid-1;
        }
        else{
             lower=mid+1;
        }
        }
        return answer;
    }
    int minimumK(vector<int>& nums) {
        //ofcurse the binary solution is used here
        // int up =*max_element(nums.begin(),nums.end());
        int up=1e9;
        int lower=1; //lower 
         // int mid=(lower+up)/2;

        return  binarys(up,lower,nums);

    }
};