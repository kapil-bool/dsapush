class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int>cnt(4,0);
        //u->1;
        //d-?2;
        // r->3;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == 'U') cnt[0]++;
            else if(moves[i] == 'D') cnt[1]++;
            else if(moves[i] == 'R') cnt[2]++;
            else if(moves[i] == 'L') cnt[3]++;
            // if(moves[i]=='R') cnt[0]++;
            
        }
            // (cnt[0]==cnt[1] and cnt[2]==cnt[3]) return true;

        return (cnt[0]==cnt[1] and cnt[2]==cnt[3]);
    }
};