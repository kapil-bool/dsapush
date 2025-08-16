class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        vector<int>a;
        int n=s.size();
        for(int i=0;i<n;i++) a.push_back(s[i]);
        bool count=0;
        for(int i=0;i<n;i++){
            if(!count and s[i]=='6'){
                s[i]='9';
                break;
            }
        }

        int ans=stoi(s);
        return ans;
    }
};