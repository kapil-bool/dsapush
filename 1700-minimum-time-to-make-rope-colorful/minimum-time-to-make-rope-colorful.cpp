class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //dp binary greedy pq thiese all will be possible
        //well dp will work but greedy may be a faster choice here 
        //INTUTOION
        /* IF THE  colur is same remove the samller one as this is the minium */
        int ans=0;
        for(int i=1;i<colors.size();i++){
            char prev_c=colors[i-1];
            if(colors[i]==prev_c){
                ans+=min(neededTime[i], neededTime[i-1]);
                //make the one with larger comparison at current position
                neededTime[i]=max(neededTime[i], neededTime[i-1]);
            }
            else{
                continue;
            }

        }
        return ans;
    }
};