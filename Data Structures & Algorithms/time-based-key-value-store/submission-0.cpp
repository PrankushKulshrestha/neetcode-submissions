class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {   
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (!mp.count(key)) {
            return "";
        }
        auto &v = mp[key];
        int left = 0;
        int right = v.size() - 1;
        string ans = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid].first == timestamp) {
                return v[mid].second;
            }   
            if (v[mid].first < timestamp) {
                ans = v[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};