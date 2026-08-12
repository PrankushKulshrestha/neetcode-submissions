class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() { 
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        vector<pair<int, string>>& arr = mp[key];
        int low = 0;
        int high = arr.size() - 1;
        string ans = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second ;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
