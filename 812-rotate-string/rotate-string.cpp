class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return 1;
        for(int i=0;i<s.size();i++){
            string temp=s;
            rotate(temp.begin(), temp.begin() + i, temp.end());
            if(temp==goal) return 1;
        }
        return false;
    }
};