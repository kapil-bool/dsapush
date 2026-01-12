class Solution {
public:
    int residuePrefixes(string s) {
        int total=0;
        set<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            if(st.size()==((i+1)%3) ) total++;
        }
        return total;
    }
};