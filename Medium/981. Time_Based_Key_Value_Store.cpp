class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        if (timestamp < mp[key][0].first) return "";

        int l = 0, r = mp[key].size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mp[key][mid].first <= timestamp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (!r) return "";

        return mp[key][r - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */