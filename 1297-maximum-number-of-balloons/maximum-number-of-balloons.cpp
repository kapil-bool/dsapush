class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //minof all the needed one and that it ;
        unordered_map<char,int>mp;
        for(auto &i:text){
            if(i=='b' ||i=='a'||i=='l'||i=='o'||i=='n'){
                mp[i]++;
            }
        }
        //check for the oo ll here
        if(mp.size()==5){
            int firstfactor;
            int cnto=mp['o'];
            int cntl=mp['l'];
            firstfactor=min(cnto/2,cntl/2);
            int firstfactorr=1e9;
            for(auto &i:mp){
                if(i.first=='o' or i.first=='l'){
                    continue;
                }
                firstfactorr=min(firstfactorr,i.second);

                //1 of this there must be 2 
                // if(firstfactorr*2<=firstfactor){
                //     return firstfactorr;
                // }
                // else{
                //     //this mean here the firstfacotr is the d factor;
                // }
            }
                return min(firstfactorr,firstfactor);
        }
        return 0;
    }
};