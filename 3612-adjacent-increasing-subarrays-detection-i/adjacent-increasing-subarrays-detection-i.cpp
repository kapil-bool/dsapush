class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        //intution if u found a valid ++ if not then what
        //so a direct window of 2k wont work here insted take 2 storing elem here which will store them 
        //and the samllest one of them should be of length k atlest to be true
        int prev=0;
        int current=0;
        int count=1; //this will be used to reset here 
        int maintainmin=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                count++;
            }
            else{
                //so here what u have to do is store in the prev one and set count back to 1
                prev=count;
                count=1;
                //basic sliding window logic here 
            }
            maintainmin=max(maintainmin,min(prev,count));
            //ooo what if there is just a single here so it should me more than 2k then
            maintainmin=max(maintainmin,count/2);// tt 1 fail if not this

            
        }
        return maintainmin>=k;
    }
};