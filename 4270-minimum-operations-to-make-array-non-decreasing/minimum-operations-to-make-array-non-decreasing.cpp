class Solution {
public:
    long long minOperations(vector<int>& nums) {
        //points dependendend hai ig; //divide into segments thats it 
        //valley is what i have to figure out;;
        long long ans=0;
        long long count=0;
        for(long long i=1;i<nums.size();i++){
            //3 cases arer here 
            //decreadsing till it decrease add x and then wjjateverdiffer is there + it simultanously
            //all increasing but below a local maxima  single time xto the range;
            //peaks and treanches that also fits in above 2;

             if(nums[i]<nums[i-1]){
                ans+=(nums[i-1]-nums[i]);
               
             }
        }
        return ans;
    }
};