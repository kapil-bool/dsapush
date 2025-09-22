class MyCalendarTwo {
public:
   map<int,int>store;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        //ok it already have plus and mius here
        store[startTime]++;
        store[endTime]--;
        // map hai so noo wooories here
        int active=0;
        for(auto &i:store){
            int time=i.second;
            active+=time;
            if(active>2){
                //will skip this also so change it 
                store[startTime]--;
                store[endTime]++;
                
                return false;
                
            }
        }
        return true;
    }
};
//3 common entries here 
//ok same here just the 3 part is there lets me solve last for the day


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */