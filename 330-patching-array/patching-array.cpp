class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //1 can be formed only from 1 
        long long ans=0;
        long long miss=1;
        long long i=0;
        //condtion is when u need to insert so that u can achieve it 
        while(miss<=n){
            //when !needed
            //if the miss is more take the number and update the miss 
            //if u can reach till the range well and good just take the i and if u can that is it is greter than the miss  one 
            if(i<nums.size()  and nums[i]<=miss){
                 //here nums[i] already can be made so  i++ and the range will be incrmted;
                 //take the number here 
                 miss+=nums[i];
                 i++;
            }
            //patch with the miss one only ;
            else{
                miss+=miss;
                ans++;
            }

        }
        return ans;
    }
};