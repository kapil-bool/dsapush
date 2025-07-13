class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
         sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        // sort(players.begin(),trainers.begin());
        int count=0;
        int pointer_forg=0;
        int pointer_fors=0;
        while(pointer_forg<players.size() and pointer_fors<trainers.size()){
            //condtion
            //equal greater or bigger
            if(players[pointer_forg]<=trainers[pointer_fors]){
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