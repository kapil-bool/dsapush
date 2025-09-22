class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //on a single line it traverse that is what it is trying to say
        //lets see 
        //here changing variable is capacty so check for the capacty at the add one if its there procede as return 0
        vector<pair<int,int>>events;
        //+1 -1 same
           for (auto &trip : trips) {
            events.push_back({trip[1], trip[0]});   
            events.push_back({trip[2], -trip[0]});  
        }
        sort(events.begin(),events.end());
        //ok now the check here
       int current=0;
     for (auto &i : events) {
            current += i.second;  
            if (current > capacity) return false;
        }
      return true;
    }
};