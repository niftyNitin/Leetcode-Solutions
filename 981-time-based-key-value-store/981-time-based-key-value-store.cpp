class TimeMap {
public:
    unordered_map<string, map<int,string>> timemap;
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(timemap.find(key) == timemap.end()) return "";
        auto iter = timemap[key].upper_bound(timestamp);
        if(iter == timemap[key].begin())    return "";
        return (--iter)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */