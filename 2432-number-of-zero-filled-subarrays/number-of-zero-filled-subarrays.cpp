class Solution {
public:
    typedef long long ll;
    ll helper(vector<int>& nums){
       ll count=0;
       ll answer=0;
       for(int i=0;i<nums.size();i++){
        // if(i==nums.size()-1 and count!=0) 
            //  answer+=count*(count+1) /2;
             
           if(nums[i]!=0){
             answer+=count*(count+1) /2;
             count=0;
           }
           else{
            count++;
           }
       }
            answer += count * (count + 1) / 2;

       return answer;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        //tring all combinations here n*(n+1)/2;
        return helper(nums);
    }
};