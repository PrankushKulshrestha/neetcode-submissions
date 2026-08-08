class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>cars(n);
        for(int i=0; i<n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        double time = (target - cars[n-1].first) / (double)cars[n-1].second;
        int count = 1;
        for(int i=n-2; i>=0; i--) {
            double ctime = (target - cars[i].first) / (double)cars[i].second;
            if (ctime>time) {
                count++;
                time = ctime;
            }
        }
        return count;
    }
};