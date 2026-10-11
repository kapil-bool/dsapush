class Solution {
public:
    int minRotations(string s) {
        int initpointer=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            //forward backard take min+=
            int target=s[i]-'0';
            int frwd=abs(target-initpointer);
            int other=10-frwd;
            ans+=min(frwd,other);
            initpointer=target;
        }
        return ans;
    }
};