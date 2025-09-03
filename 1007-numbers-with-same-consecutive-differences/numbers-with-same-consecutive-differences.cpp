class Solution {
public:
   vector<int>ans;
    void helper(int num,int length,int k,int n){
        if(length==n){
            ans.push_back(num); //all iteration from  t0 9 
            return;
        }
        int last=num%10;
        //now handel the k think or the next number
        if(last+k<10){
            //then directly just take it if its more than 10 then a issue;
            helper(num*10+(last+k),length+1,k,n);
        }
            //10 last-k so it is again in the range
        if (k != 0 && last - k >= 0) {
            helper(num * 10 + (last - k), length + 1, k, n);
        }

    }
    vector<int> numsSameConsecDiff(int n, int k) {
        //will do u also today only be ready
         //n=9 at max so not bf will work here 
         //since no leeding zeroes 1 se start hona chaniye
         ans.clear();
        for(int i=1;i<=9;i++){
            helper(i,1,k,n);
        }
        return ans;
    }
};