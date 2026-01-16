class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        //question of choice here 
        //dp will work ut overkill so go with greedy
        //equal skip else make a decision
        int n=s.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i]==t[i])continue;
           else if (s[i] == '0')
              a++;
            else{
                b++;
            }
        }

        //now see what cost is better if u are at last only one is left then flip will be there no exeption
        //min mis matches
        long long minc=min(a,b); //make the min one that is
      //flip all
      long long z=a+b;
      long long flipc=z*flipCost;
      //swap cost min will decide 
      long long scost=1LL*minc*swapCost;
      //   now remaing one  u do full flip 
        //in the last one distinct one 1 operatoion will do 2 fixes and the reming if odd that is only one flip the bit  
        //cross cost and swap both willl be involved  here
        long long rem = z - 2 * minc;

        
        long long costas = scost + rem * flipCost;

    
        long long fcost = scost + (rem / 2) * (crossCost + swapCost) + (rem % 2) * flipCost;

        return min(flipc, min(costas, fcost));
        
    }
};