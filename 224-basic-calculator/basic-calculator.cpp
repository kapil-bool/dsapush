class Solution {
public:
int helper(int &index,string &s){
   //till u reach end
   int number=0;
   int current_sum=0;
   int sign=1;
   while(index<s.size()){
      //left to right calu to be done ( +,- ,) these cases are there and avoid the spaces here
      char c=s[index];
      index++; //here it is done so if u got (  then u can alrady jump to the next one 
      if(isdigit(c)){
        //like 34 here is first 3 is read than before next 10 multiply and then add it
         number=number*10 + (c-'0'); //now will exectute perffectly
      }
      else if(c=='+'){
         current_sum+=number*sign;
         number=0; //next beginning
         sign=1;
      }
      else if(c=='-'){
         current_sum+=number*sign;
         number=0;
         sign=-1;
      }
      // ( now manage these to also)
      else if(c=='('){
        //this means a sub broblem is there
        int sub_p=helper(index,s);
        //add this sub problem to the current sum
        current_sum+=sub_p*sign;
        number=0;
        //exit from here now )
      }
      else if(c==')'){
        //this is more like the end of a expresssion so u just exit from it 
        //sub base case and base case
        //so u return when u reach the base case
        //( so here expression will be calulated under sub_p so here also current sum will be there)
          current_sum += number * sign;
          return current_sum;
      }
     
   }
   current_sum+=number*sign;
   return current_sum;
}
    int calculate(string s) {
        //so here my intution is as u see ( while iterating from left to right u store pause and store the current one and start the sub problem calulation and return it to the main onw
        //base case is when u reach the end
        int index=0;
        int ans=helper(index,s);
        return ans;
    }
};