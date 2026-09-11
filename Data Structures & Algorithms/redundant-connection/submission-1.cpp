class Solution {
public:
    vector<int> parent, rank_;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            if (!unite(a, b))
                return {a, b};
        }
        return {};
    }
};
