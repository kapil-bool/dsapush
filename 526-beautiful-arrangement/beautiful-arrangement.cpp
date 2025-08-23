class Solution {
public:
 int count=0;
    int helper(int index,int n,vector<bool>&used){
        if(index>n){
            count++;
            return{};
        }
        for(int i=1;i<=n;i++){
            if(!used[i]and (i%index==0  or index%i==0)){
                used[i]=1;
                helper(index+1,n,used);
                used[i]=0;
            }
        }
       return count;
    }
    int countArrangement(int n) {
        //let me do this also
        //brute force is generate all and check them but tle 
        //n=1 [1,2] 1 satisfide 2 satisfied u reach end count++
        //logic is like a temp variable and checkhere if u reach thebend andsatified ++ the count and return 
        //ok when to take is perm[i] is divisible by i.
        //i is divisible by perm[i]. any of them and in permutaion only  one time is used
        vector<bool>used(n+1,0);
        return helper(1,n,used);

    }
};