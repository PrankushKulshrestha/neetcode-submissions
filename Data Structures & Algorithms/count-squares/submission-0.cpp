class CountSquares {
    map<pair<int,int>, int> mp;
public:
    CountSquares() {}
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
        for (auto &[p, freq] : mp) {
            int x2 = p.first, y2 = p.second;
            if (x2 == x || y2 == y) continue;
            int d = abs(x2 - x);
            if (abs(y2 - y) != d) continue;
            ans += freq * mp[{x, y2}] * mp[{x2, y}];
        }
        return ans;
    }
};
