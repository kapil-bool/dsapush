class Solution {
public:
    int countMonobit(int n) {
        //0 1  11  111  1111
        int count=0;
        for(int i=0;i<=n;i++){
            if(i==0) count++;
            else if( (i&(i+1))==0) count++;
        }
        return count;
    }
};