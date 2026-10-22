// For each key, binary search the element at the largest timestamp <= query timestamp

class TimeMap {
    unordered_map<string, vector<string>> vals;
    unordered_map<string, vector<int>> timestamps;
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        vals[key].push_back(value);
        timestamps[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!vals.count(key)) return "";

        // Returns smallest timestamp for key > query timestamp
        auto it = upper_bound(timestamps[key].begin(), timestamps[key].end(), timestamp);

        if (it == timestamps[key].begin()) return "";
        int i = it - timestamps[key].begin() - 1;
        return vals[key][i];
    }
};
