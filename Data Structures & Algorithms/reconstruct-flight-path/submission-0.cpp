class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (auto& ticket : tickets)
            adj[ticket[0]].push(ticket[1]);
        vector<string> ans;
        function<void(string)> dfs = [&](string u) {
            while (!adj[u].empty()) {
                string v = adj[u].top();
                adj[u].pop();
                dfs(v);
            }
            ans.push_back(u);
        };
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
