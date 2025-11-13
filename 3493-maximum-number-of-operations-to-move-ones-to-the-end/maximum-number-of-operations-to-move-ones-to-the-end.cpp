class Solution {
public:
    int maxOperations(string s) {
        //00000 treat it as a single grp 
        //111 as also a single grp 
        int zero=0;
        int ones=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
        //2 cases are here
           if(s[i]=='0'){
               while((i+1)<s.size() and s[i+1]=='0'){
                 //in this case a single grp is considered 
                  i++;
               }
               ans+=ones;
           }
           else{
             ones++;
           }
        }
    return ans;
    }
};
/* "111001010"
  001111010 till here 3 and no of 1 =4;
  next 0 is there move willcount of zero of ++ of inxdex will be there till another 1 is there 
  000111110 3+4=7 no of ones =5
  and in next step 
  7=5=12 ig 
  */