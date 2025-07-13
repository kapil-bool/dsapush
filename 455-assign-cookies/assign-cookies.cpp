class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        // sort(g.begin(),s.begin());
        int count=0;
        int pointer_forg=0;
        int pointer_fors=0;
        while(pointer_forg<g.size() and pointer_fors<s.size()){
            //condtion
            //equal greater or bigger
            if(g[pointer_forg]<=s[pointer_fors]){
                count++;
                pointer_forg++;
                //so is the cookie can only be used ones
                pointer_fors++;

            }
            else{
                pointer_fors++;
            }
        }
        return count;
    }
};