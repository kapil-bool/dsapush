class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        //okay let me do it also last for today
        //if all are differnt u are good to go //no worries at all 
        //no of zeroes will oplay a role
        //next occurance is also important 
        //1 2 0 1 2 0 this is a diifernt one 
        //so if overflow is ther [] just this 
        // When you encounter a dry day (rains[i] == 0), you can choose which lake to dry.

// The key is prioritize lakes that will rain again soon (i.e., the next rain on that lake could cause a flood). this is the main thing 
//next that appear and is already full
       int n = rains.size();
        vector<int> ans(n, 1);         
        unordered_map<int,int> full;     
        set<int> dryDays;                  
     for(int i=0;i<n;i++){
        if(rains[i]==0) dryDays.insert(i); //index here
     else{
        //check if it is full already that is it is addedinto the map;
        int lake=rains[i];
        if(full.count(lake)){
            //present hai already so it should be emptyies for that i nedd a 0 that is smller thean current i which i will get from the drydays one
            //   auto it = dryDays.upper_bound(full[lake]);
               auto it = dryDays.upper_bound(full[lake]); //strictly greater than the filled lake index
                    if(it == dryDays.end()) return {}; //no 0 is there
                    ans[*it] = lake;    //yes it is there and assign the lake here   
                    dryDays.erase(it);  //erase this now 

        }
        full[lake]=i;
        ans[i]=-1;
       }
      }
      return ans;
    }
};