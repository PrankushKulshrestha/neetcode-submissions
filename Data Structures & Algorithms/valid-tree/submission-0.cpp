class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        if (!dfs(0, -1, adj, visited)) return false;
        return visited.size() == n;
    }
private:
    bool dfs(int node, int parent, const vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (visited.count(neighbor)) return false;
            if (!dfs(neighbor, node, adj, visited)) return false;
        }
        return true;
    }
};