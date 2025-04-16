class Solution {
public:
    int longestContinuousSubstring(string s) {
        int length=1;
        int count=1; //minimum is one constarins me given hai
        int n=s.size();
        for(int i=1;i<n;i++){
           //basiclly idhar  par  differ bw two shold not be more than 1;
           if((s[i]-s[i-1])==1) count++;
           else{
              length=max(length,count);
              count=1;//reseting the count
           }
              length=max(length,count);
        }
        return length;
    }
};