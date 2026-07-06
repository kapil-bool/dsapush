class Solution {
public:
     map<int,int>mp;
     int calci(int x){
        int mini=1e9;
        int maxi=-1e9;
        while(x){
           int test=x%10;
           mini=min(mini,test);
           maxi=max(maxi,test);
           x=x/10;
           //done now
        }
        return abs(mini-maxi);
     }
    int maxDigitRange(vector<int>& nums) {
        for(auto &i:nums){
            int num=i;
            // if(calci(i)!=mp.end()){
            //     mp[calci(i)]+=i;
            // }
            // else{
            //     //it esist;
                mp[calci(i)]+=i;
            // }

            // //well will do the same thing only
        }
        return mp.rbegin()->second;
    }
};