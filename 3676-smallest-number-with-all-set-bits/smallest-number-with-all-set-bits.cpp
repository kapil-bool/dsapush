class Solution {
public:
    int smallestNumber(int n) {
        int count=0;
        string s = bitset<32>(n).to_string();
        s.erase(0, s.find('1'));
        // int  first=1;
        int len=s.size();
        int ans=0;
        while(len){
           ans = (ans << 1) + 1;
           len--;
        }

        return ans;
    }
};