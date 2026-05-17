class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int differnce=3;
        int n=s.size();
        for(int i=1;i<n;i++){
              int differ=abs(s[i]-s[i-1]);
            //   cout<<differ<<endl;
            if(differ>=3){
                return 0;
            }
        }
        return 1;
    }
};