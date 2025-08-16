class Solution {
public:
   vector<vector<int>> dp;

   bool helper(int index,int index2,string &s,string &p){
      if(dp[index][index2] != -1) return dp[index][index2];

      if(index2==p.size()) 
         return dp[index][index2] = (index==s.size()); //base case hai
      
      //also the compare ? and s[i]==j[i];
      if((index < s.size() && p[index2]=='?') || (index < s.size() && s[index]==p[index2])){
         return dp[index][index2] = helper(index+1,index2+1,s,p);
      }

      //now the star case
      if(p[index2]=='*'){
         bool case1 = helper(index, index2+1, s, p); // * = empty
         bool case2 = (index < s.size()) && helper(index+1, index2, s, p); // * consumes one char
         return dp[index][index2] = (case1 || case2);
      }
      
      return dp[index][index2] = false;
   }

   bool isMatch(string s, string p) {
      dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
      return helper(0,0,s,p);
   }
};

/* so two pointers are to be marked here ? condtion easy to implment
 *-> 2 case 1. stop it right there basically 0
 case2. is like when to stop it how can i do this 
 //make it a dp one mel is showing
*/