class MyCalendar {
private:
    map<int, int> events; // key = time, value = +1 for start, -1 for end
public:
    MyCalendar() {
        events.clear();
    }

    bool book(int start, int end) {
        // Add the new event tentatively
        events[start]++;  // start of interval
        events[end]--;    // end of interval

        int active = 0;
        for (auto &e : events) {
            active += e.second;
            if (active > 1) {      // overlap detected
                // revert the tentative addition
                events[start]--;
                events[end]++;
                if (events[start] == 0) events.erase(start);
                if (events[end] == 0) events.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
 //ok will do u 