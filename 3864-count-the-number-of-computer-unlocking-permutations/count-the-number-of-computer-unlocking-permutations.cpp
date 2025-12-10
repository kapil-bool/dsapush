class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        //n or logn 
        //if the min elemnt is not the first one return 0;
        //logn
        int mi=*min_element(complexity.begin()+1,complexity.end()); 
        if(mi<=complexity[0]) return 0;
        // 123-> 1 ->3 and then 2 also from 1 this is one possiblity or in order solve it ans is 2
        //combination apply karo
        //now combination of all the reming n-1 will be answer
        long long MOD =1e9+7;
        long long si=complexity.size()-1;
        long long ans=1;
        while(si>=2){
            ans=(ans*si)%MOD;
            si--;
        }
        return ans;

    }
};