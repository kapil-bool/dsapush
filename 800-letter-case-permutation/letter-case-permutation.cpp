class Solution {
public:
 vector<string>ans;
 vector<string> helper(int index,string s){
   //2 cases honge
   if(index==s.size()){
    ans.push_back(s);
     return {};
   }
   if(isalpha(s[index])){
       //now 
       s[index]=tolower(s[index]);
       helper(index+1,s);
       s[index]=toupper(s[index]);
       helper(index+1,s);

   }
   else{
    helper(index+1,s); //just to the next one
   }
   return ans;
 }
    vector<string> letterCasePermutation(string s) {
        //  helper(0,s);
         return   helper(0,s);
    }
};