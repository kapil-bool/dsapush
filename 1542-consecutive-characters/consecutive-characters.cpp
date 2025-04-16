class Solution {
public:
    int maxPower(string s) {
        int right=0,left=0;
        int maxlen=0;
        while(right<s.size()){
            if(s[right]==s[left])right++;
            else{
                //ek lenght to hogi he naa
                maxlen=max(maxlen,right-left);
                left=right;

            }

        }
       maxlen=max(maxlen,right-left);
       return maxlen;
    }
};