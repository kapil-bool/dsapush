class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        //current one one in next one count 
        int prev=0;
        int ans=0;
        for(auto &i : bank){
            //count 1 in this ;
            int count=0;
            for(auto &c :i){
                if(c=='1')  count++;
            }

            if(count!=0){
                ans+=prev*count;
                prev=count;
            }
        }
        return ans;
    }
};