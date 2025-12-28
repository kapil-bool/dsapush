class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //how cost selection to be done that is the question here
        //bundel or indivi how u want to buy that is the question here
        long long  ans=0;
        if((cost1+cost2)>costBoth){
            //here first the remaing amout in bundel
            ans+=1LL* min( need1,need2)*costBoth;
            if(need1>need2){
                ans+=1LL* (need1-need2)*min(cost1,costBoth);
            }
            else if(need2>need1){
                ans+=1LL*((need2-need1))*min(cost2,costBoth);
            }
        }
        else{
            //this case take individual answer
            ans+= 1LL*need1*cost1 + 1LL*need2*cost2;
        }
        //remaing one will be handele
        return ans;
    }
};