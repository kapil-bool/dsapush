class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int answer=0;
        sort(nums.begin(),nums.end());
        //n is even already mentioned 
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int  current=nums[i]+nums[j];
            answer=max(answer,current);
            i++;
            j--;
        }
        return answer;
    }
};