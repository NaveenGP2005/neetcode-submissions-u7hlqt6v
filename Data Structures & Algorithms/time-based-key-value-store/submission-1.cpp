class TimeMap {
public:

    map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()) {
               auto &inner = mp[key];
            auto it = inner.upper_bound(timestamp);

            // case 1: all timestamps <= timestamp
            if (it == inner.end()) {
                it--;  // last valid timestamp
                return it->second;
            }

            // case 2: exact match is impossible with upper_bound,
            // so we skip the if(it->first == timestamp)

            // case 3: it is begin() → nothing <= timestamp
            if (it == inner.begin()) {
                return "";
            }

            // case 4: element <= timestamp is previous one
            it--;
            return it->second;
        }
        return "";
    }
};
