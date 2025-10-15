class Solution {
public:
    string s;
    int dp[11][2]; //1e9 and 2 bool, value
    int helper(int index, int tight,vector<int>&digit_num){
        //no prev and leeding neede 
        if(index==s.size()) return 1;
        if(dp[index][tight]!=-1) return dp[index][tight];
        //lb and ub 
         int ub=(tight)? s[index]-'0' : 9;
         int ans=0;
         for(auto &i:digit_num){
            //so if the number picked is more than upper bound leave 
            if(i>ub) break;
            else{
                //tight and (digits[i]==(ub)
                ans+=helper(index+1,(tight and (i==ub)),digit_num);
            }
         }
         return ans;
    }
    //i think this is enoufg
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        //till now i was using tight as u get a number less thanor eqaul but not greter so use the same here
        //and used to pick like nums[i]-'0' : 9 but here i will chose from the digits 
         vector<int> digit_num;
         for(auto &i:digits){
            digit_num.push_back(i[0]-'0');
            sort(digit_num.begin(),digit_num.end());
         }
         
         memset(dp,-1,sizeof(dp));
         s=to_string(n); //upper boundere here 
         int temp=helper(0,1,digit_num);
         //no i also need all possble digits here like if n=3 all 2 and 1 will be ther e
         int lenpossible=s.size();
         int m=digit_num.size();
          int product=1;
          int add=0;
         for(int i=1;i<lenpossible;i++){
            //how many possible of a digit is taht into no of total
            // [1,2,3,4]{1,12,13,14,21,31,41,11} //one in single and other 1+4+3
            product*=m;
            add+=product;

         }
         return temp+add;
         
    }
};