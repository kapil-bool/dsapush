class Solution {
public:
const long long MOD = 1e9 + 7;
    long long helper(long long base,long long expo){
        //so here total no of even and odd possible wile be calulatef and retuned
        long long ans=1;
        while(expo>0){
            if(expo%2==1){
                //this means its odd so odd
                ans=(ans*base)%MOD;
            }
            //else the even case so 5 option here
            //here base is doubled 
            /* power(4,5)-> 4*power(4,4) or just power(16,4)*/
            base=(base*base)%MOD;
            expo=expo/2;
        }
        return ans;

    }
    int countGoodNumbers(long long n) {
        //recursion se he hoga
        //bf: its like generate all and check but may give tle
        //odd =2,3,5,7
        //evenindex= or 1 and index==index its modulo of to 
        //count odd and even so odd can only have 4 options *no of ways
        //similary even*no of ways 2,4,6,8,0 so five here
        long long evenindex=(n+1)/2; //what ceil value lena
        long long oddindex=n/2;
        long long optionsforeven=helper(5,evenindex);
        long long optionsforodd=helper(4,oddindex);
        long long ans=(optionsforeven*optionsforodd)%MOD;
        return ans;
    }
};