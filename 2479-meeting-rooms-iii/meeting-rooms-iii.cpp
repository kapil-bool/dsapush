class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Each meeting will take place in the unused room with the lowest number. pq here 
        //If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting. this mean no incremt in time and all as a whole but  delay time will be there + on both end 
        //When a room becomes unused, meetings that have an earlier original start time should be given the room. inital one with smmler s stime will be first
        //simulation hai 
        sort(meetings.begin(),meetings.end());
        //count of acces also
        vector<long long>count(n,0); //access when u try to a new one and it is empty;
        priority_queue<int,vector<int>,greater<int>>rooms;
         priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> busy;
            //here what i can do is the meeting with time right
        for (int i = 0; i < n; i++) rooms.push(i);
        for(auto &i:meetings){
            //busy->remove the samllest one and also reduce all other by same 
            auto start=i[0];
            auto end=i[1];
            auto dua=end-start;

            while(!busy.empty() and busy.top().first<=start){
                //remove this and put into the pq and also the count need to be handeled here
                rooms.push(busy.top().second);
                busy.pop();
            } //reuse if it empty as maximum utilization 
            //rooms are free allote them
            if(!rooms.empty()){ //empty room pick it from tp and push into the busy one
                //rooms.que tp will be 0 indicating it is empty
                int tproom=rooms.top();
                busy.push({end,tproom});
                rooms.pop();
                count[tproom]++;
            }
            
            //no rooms are free
            else{
                auto[endT,rm]=busy.top();
                //now take the time 
                // auto time=end-start;
                //hoga  bhi topof q he kali room bhi wahi milega 
                busy.pop();
                busy.push({endT+dua,rm});
                count[rm]++;
            }
        }
       int ans=0;
       for(int i=1;i<n;i++){
        if  (count[i]>count[ans]){
        ans=i;}
       }
       return ans;
    }
};