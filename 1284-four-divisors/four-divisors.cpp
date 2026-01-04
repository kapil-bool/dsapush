class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long aggregatesum = 0;
        //square root decomposition use it 
        for (long long i = 0; i < nums.size(); i++) {
            long long tested = nums[i];
            long long count = 0;
            long long sum = 0;

            for(long long j=1;j*j<=tested;j++){
                if(tested%j==0){
                    count++;
                    long long first=j;
                    long long otherpossible=tested/j;
                    sum+=first;
                  
                  if(first!=otherpossible){
                     count++;
                     sum+=otherpossible;
                  }

                if(count>4) break;
                }
               }
                 if(count==4 ){
                 aggregatesum+=sum;
            }
        }
        return aggregatesum;
    }
};
