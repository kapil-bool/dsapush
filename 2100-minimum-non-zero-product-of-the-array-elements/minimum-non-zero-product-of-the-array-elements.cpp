class Solution {
public:
    typedef long long ll;
    static const ll MOD = 1000000007LL;  

    ll helper(ll base, ll exp) {
        ll result = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        ll maxNum = (1LL << p) - 1;
        ll secondMax = maxNum - 1;
        ll times = (1LL << (p - 1)) - 1;

        ll ans = helper(secondMax, times);
        ll maxNum_mod = maxNum % MOD;

        ll finalResult = (ans * maxNum_mod) % MOD;
        return (int)finalResult;
    }
};


        //make any one zero and u have an answer 
        //so make the pairs of largest one as 1 2 3 4 5 6 7 
        //like here the sec_.lar=6 if i reduce it to 5 and other 1 to to any thing other than one it will increase the set bit some where alse as a rwesult it will be maximised
        //so her total o of times it will be usedd is half of of totAl-1/2