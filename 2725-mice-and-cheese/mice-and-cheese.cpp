class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        //mouse 1 eats k piece remaing by the second one 
        //difference array whre the gain is man=ximum for the mouse 1 for k terms i take them and remianng from reward2
        int n=reward1.size();
        vector<int>differ(n);
        // int answer=0;
        for(int i=0;i<n;i++){
            differ[i]=reward1[i]-reward2[i];
        }
        //sort it
        sort(differ.begin(),differ.end());
        
         int answer=accumulate(reward2.begin(),reward2.end(),0);
        //add the k from differ
        int index=n-1;
        while(k){
           answer+=differ[index];
           index--;
           k--;
        }
 return answer;
    }
};