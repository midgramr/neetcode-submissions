class TimeMap {
    // Conceptually, we can model this as a hashtable of sorted arrays
    unordered_map<string, vector<int>> ts;
    unordered_map<string, vector<string>> vs;
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        ts[key].push_back(timestamp);
        vs[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if (!ts.count(key)) return "";
        // Want the last value in mp[key] where ts <= timestamp
        // i.e., search for the first timestamp that's greater then decrement by one
        auto it = upper_bound(ts[key].begin(), ts[key].end(), timestamp);
        if (it == ts[key].begin()) {
            return "";
        }
        return vs[key][prev(it) - ts[key].begin()];
    }
};
