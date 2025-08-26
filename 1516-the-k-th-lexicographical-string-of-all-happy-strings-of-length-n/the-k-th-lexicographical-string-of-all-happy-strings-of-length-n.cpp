class Solution {
public:
   string ans="";
    string helper(int n,int k){
        int total=3*pow(2,n-1); //always 2 options
        if(total<k) return "";
        //now the selection of the char 
        char prev=0; //here the current used one to be put 
        for(int i=0;i<n;i++){
            int grp=pow(2,n-1-i);
           //how to pick the char here is the question?
           for(char c='a';c<='c';c++){
              //if the c is eqaul to prev i skip it 
              if(c==prev) continue;
              if(k>grp){
                k=k-grp; //kind of bits--
              }
              else{
                //u pich it 
                 prev=c;
                 ans.push_back(prev);
                 break;
              }
           }
        }

       return ans;
    }
    string getHappyString(int n, int k) {
        //n-- for the lenth 
        //so insted of creating all the strings here i will do it something like lc 60 
        //each car will have 2 option so this will give me the the initall char for selection
        //2 options are till n-1 times so 
        return helper(n,k);
    }
};