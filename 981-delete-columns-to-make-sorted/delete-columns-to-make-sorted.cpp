class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //brute force
        int count=0;
        int n=strs.size();
        int ptr_char=0;

       while(ptr_char<strs[0].size()){
          for(int i=1;i<n;i++){
            if(strs[i][ptr_char]>=strs[i-1][ptr_char]) continue;
            else{
             count++;
             break;}
          }
          ptr_char++;
       }
        return count;
    }
};