class Solution {
public:
    vector<int> parent;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        parent.assign(n, 0);
        for (int i=0; i<n; i++) parent[i] = i;
        for (const vector<int>& edge : edges) {
            int root1 = find(edge[0]);
            int root2 = find(edge[1]);
            if (root1 == root2) 
                return false;
            parent[root2] = root1;
        }
        return true; 
    }
    int find(int node) {
        while (node != parent[node])
            node = parent[node];
        return node;
    }
};
