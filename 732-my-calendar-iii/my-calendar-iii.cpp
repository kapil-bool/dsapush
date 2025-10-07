class MyCalendarThree {
//line sweep will work fine i guess 
//on;y way is 10^9 usually a gement tree compression approch 
private:
    map<int, int> events; // key = time, value = net change (+1 start, -1 end)
public:
    MyCalendarThree() {
        events.clear();
    }

    int book(int start, int end) {
        // Add the new interval events
        events[start]++;  // start of interval
        events[end]--;    // end of interval

        // Sweep through events to find current max overlap
        int active = 0;
        int maxOverlap = 0;
        for (auto &e : events) {
            active += e.second;
            if (active > maxOverlap)
                maxOverlap = active;
        }

        return maxOverlap;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */