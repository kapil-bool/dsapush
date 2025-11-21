class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>storeletter;
        int ans=0;
        for(char ch:s){
            //storing the occurancer in mapcreated;
            storeletter.insert(ch);
        }
        for(char ch2: storeletter){
            int i=-1,j=-1;//because we dont know the first or last ocurance of the letter so we take -1;
            for( int z=0 ;z<s.size();z++){
                //if it is the first occucane storethe index in i else in j;
                if(s[z]==ch2){
                    if(i==-1) i=z;
                    else j=z;
                }
            }
            //now create another hash set and find the unique charater 
            unordered_set<char> uniqueelem;
            for(int k=i+1;k<j;k++){
                uniqueelem.insert(s[k]);
            }
            ans+=uniqueelem.size();
        }
       return ans;
    }
};