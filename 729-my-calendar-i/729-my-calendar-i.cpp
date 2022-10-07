class MyCalendar {
public:
    set<pair<int,int>> calender;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        pair<int, int> event{start, end};
        auto nextEvent = calender.lower_bound(event);
        if(nextEvent != calender.end() and nextEvent->first < end)
            return false;
        if(nextEvent != calender.begin()) {
            auto prevEvent = prev(nextEvent);
            if(prevEvent->second > start)
                return false;
        }
        calender.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */