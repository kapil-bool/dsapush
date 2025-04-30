class Solution {
public:
    int findNumbers(vector<int>& nums) {
        long long count=0;
        for(long long i=0;i<nums.size();i++){
            long long digit=nums[i];
           long tempsize=0;
            while(digit>0){
               
                    //calulate the size of count;
                
                digit=digit/10;
                tempsize++;
            }
                    if(tempsize%2==0)count++; 
        }
        return count;
        
    }
};