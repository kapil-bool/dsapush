class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            //for 1 <= low <= high <= 10^4 means 10000
            //3 wqale to possible henahi hai
            if(i<100 and i%11==0)count++;
            else if(i<10000 and  1000<=i){
                int left=(i%100)/10+i%10;
                int right=(i/1000)+(i%1000)/100;
                if(left==right)count++;
            }
        }
       return count;
    }
};