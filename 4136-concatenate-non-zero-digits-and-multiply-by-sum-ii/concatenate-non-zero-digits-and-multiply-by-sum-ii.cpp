class Solution {
public:
    const int modulo=1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        //brute forces is fked 
        //from current postion to the whatever no of digits thats it
        vector<int>ans;
        int n=s.size();
        vector<ll>prefix(n+1,0);
        vector<int>prefixs(n+1,0); //sum 
        vector<int>prefixd(n+1,0);
        //store and like that u need deletions only so find the first occurance and de;ete it  accordingly
        for(int i=0;i<n;i++){
            //if it not 0 then it changes else u make changes
            prefix[i+1]=prefix[i];
            prefixs[i+1]=prefixs[i];
            prefixd[i+1]=prefixd[i];

            int current= s[i]-'0';
            if(current!=0){
                prefix[i+1]=(prefix[i]*10+current)% modulo;
                prefixs[i+1]=prefixs[i]+current;
                prefixd[i+1]++;
            }
            //if not then just copy the prefious one 
        }
        vector<ll>pwr(n+1,1);
        for(int i=1;i<=n;i++){
            pwr[i]=(pwr[i-1]*10)%modulo;
        }
        //now procede the queriesl
        for(auto &i: queries){
            int l=i[0];
            int r=i[1];
            //to return ud the diit *sum
            ll sumexist=prefixs[r+1]-prefixs[l];
            ll digitcount=prefixd[r+1]-prefixd[l];
            //number is obtained here but in neg

            // ll x= ((-prefix[l]*pow(10,digitcount)+prefix[r+1]))%modulo;
            ll x=((prefix[r+1]- 1LL*prefix[l]*pwr[digitcount]%modulo+modulo))%modulo;
            ans.push_back(x*sumexist%modulo);
            

        }
        return ans;

    }
};