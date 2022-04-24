class UndergroundSystem {
public:
    unordered_map<string, pair<long long, int>> stationTimes;
    unordered_map<int, pair<string, int>> inTransit;
   
    UndergroundSystem() {
        stationTimes.clear();
        inTransit.clear();
    }
   
    void checkIn(int id, string stationName, int t) {
        if(inTransit.find(id) != inTransit.end())   return;
        inTransit[id] = {stationName, t};
    }
   
    void checkOut(int id, string stationName, int t) {
        auto& info = inTransit[id];
        string startStation = info.first;
        int startTime = info.second;
        string key = startStation + ":" + stationName;
        int time = t - startTime;
       
        if(stationTimes.find(key) != stationTimes.end()){
            auto& data = stationTimes[key];
            data.first += time;
            data.second++;
        }
        else{
            stationTimes[key] = {time, 1};
        }
        inTransit.erase(id);
    }
   
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto& data = stationTimes[key];
        return (double)data.first / data.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */