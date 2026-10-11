class Solution {
public:

    int minRotations1(string &s) {
        int initpointer = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int target = s[i] - '0';
            int frwd = abs(target - initpointer);
            int other = 10 - frwd;
            ans += min(frwd, other);

            initpointer = target;
        }

        return ans;
    }

    int minRotations(int n, string s) {
        vector<int> prefix(n + 1, 0);
        int ans=1e9; //store for the zero one this one 
        for (int i = 0; i < n; i++) {
             int initpointer = (i == 0 ? 0 : s[i - 1] - '0');
                int target = s[i] - '0';

              int frwd = abs(target - initpointer);
             int other = 10 - frwd;
              prefix[i + 1] = prefix[i] + min(frwd, other);
            // cout << prefix[i + 1] << " ";
        }

       //now possiblites of cut from 0 to n-1 possition ;
       for(int i=0;i<n;i++){
            //i think  0 is not needded 
            // if(i==0){
            //     ans=min(ans,prefix[n]);
            // }
            // else{
                int temp=prefix[n]-prefix[i+1];//unchandeg segement;
                int incl=prefix[i];
                temp+=incl;
                // now the differ segment is what i need
                 int initpointer = (i==0?0:s[i-1]-'0');
            int anss = 0;
        //   for (int i = 0; i < s.size(); i++) {
            int target = s[n-1] - '0';
            int frwd = abs(target - initpointer);
            int other = 10 - frwd;
            anss += min(frwd, other);

           
             temp+=anss;

              ans=min(temp,ans);

            

          
           

       }
       return ans;
    }
};