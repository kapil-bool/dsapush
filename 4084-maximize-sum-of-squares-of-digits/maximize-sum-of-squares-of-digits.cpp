class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //less than 9 and more than 9 2 cases 
        string ans="";
        // if(sum<10){
        //     ans+=sum;
        //     for(int i=0;i<num-1;i++){
        //           ans+=0;
        //     }
        // }
        // else{
        //     while(sum>=9 and num!=0){
        //         string+=9
        //     }
        // }
        
        if( sum> (9*num) ){
             return ans;
        }

        while(sum>=9 ){
            ans+='9';
            sum-=9;
        }
        //now it is less than 9 but but not 0;
        char inst=sum+'0';
        // cout<<inst;
        if(inst>=1 and ans.size()<num){
        ans+=inst;
        }
        cout<<ans;
        
        // int sz=ans.size();
        
        while(ans.size()<num){
            ans+='0';
        }
        // cout<<ans;
        return ans;

    }
};