class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            //for 1 <= low <= high <= 10^4 means 10000
            //3 wqale to possible henahi hai
            if(i<100 and i%11==0)count++;
            else if (i >= 1000 && i < 10000) {
                //since limit is mentioned here u can use a for loop till 2 one 
                std::string str = std::to_string(i);
                int n=str.length();
                int half=str.length()/2;
                int right=0;
                for(int j=half;j<n;j++){
                    right+=int(str[j]-'0');
                }
                int left=0;
                for(int j=0;j<half;j++){
                    left+=int(str[j]-'0');
                }
                if(right==left)count++;
                
            }
        }
       return count;
    }
};