class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //(while carry)+digits[i]>9->0 and carry =1 else carry+1 and carryt=false;
        int carry=1;
        vector<int>ans;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(carry){
                if((carry+digits[i])>9){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(carry+digits[i]);
                    carry=0;
                }
            }
            else{
                ans.push_back(digits[i]);
            }
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};