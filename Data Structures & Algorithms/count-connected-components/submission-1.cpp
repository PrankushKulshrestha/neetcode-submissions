class DSU {
 private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findP(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findP(parent[node]);
    }
    bool unionSets(int a, int b) {
        int pa = findP(a);
        int pb = findP(b);
        if(pa == pb) return false;
        if(rank[pa] < rank[pb]) {
            parent[pa] = pb;
            rank[pb] += rank[pa];
        } else {
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
        return true;
    }
};
class Solution {
public:
    
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components = n;
        for(auto edge : edges) {
            if(dsu.unionSets(edge[0], edge[1])) --components;
        }
        return components;
    }
};
