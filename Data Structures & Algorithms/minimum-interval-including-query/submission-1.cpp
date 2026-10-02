class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> q;
        for (int i = 0; i < queries.size(); ++i) {
            q.push_back({queries[i], i});
        }
        // query, index
        sort(q.begin(), q.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // len, endIndex

        vector<int> ans(q.size(), -1);
        int j = 0;
        for (int i = 0; i < q.size(); ++i) {
            while (!pq.empty() && pq.top().second < q[i].first) {
                pq.pop();
            }
            while (j < intervals.size() && intervals[j][0] <= q[i].first) {
                if (intervals[j][1] >= q[i].first) {
                    pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
                }
                j += 1;
            }
            if (!pq.empty()) ans[q[i].second] = pq.top().first;
        }
        return ans;
    }
};
