class Solution {
public:
    unordered_map<int, bool> order;
    int val;
    int cycle(int ind, vector<int>& vis, vector<vector<int>>& adj, int parent) {

        if(vis[ind] == 1) return ind;
        if(vis[ind] == 2) return false;

        vis[ind] = 1;
        for(int i = 0; i < adj[ind].size(); i++) {
            if(vis[adj[ind][i]] != 2 && adj[ind][i] != parent) {
                val = cycle(adj[ind][i], vis, adj, ind);
                if( val != -1) return val;
            } 
        }
        vis[ind] = 2;
        return -1;
    }

    bool build(int ind, vector<vector<int>>& adj, int parent, int start) {
        if (ind == start && ind != parent) return true;
        order[ind] = true;
        //cout<<ind<<" a"<<endl;
        for(int i = 0; i < adj[ind].size(); i++) {
            if(adj[ind][i] != parent && (!order[adj[ind][i]] || adj[ind][i] == start) && build(adj[ind][i], adj, ind, start)) {
                // cout<<ind<<" "<<i <<" "<< adj[ind][i]<<" b"<<endl;
                // cout<<order[ind]<<endl;
                return true;
            } 
        }
        order[ind] = false;
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> ans;
        vector<int> vis(n+1, 0);

        vector<vector<int>> adj(n+1);

        for(int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++) {
            if(vis[i] != 2){
                val = cycle(i, vis, adj, -1); 
                if(val != -1) {
                    //cout<<val<<" v"<<endl;
                    build(val, adj, val, val);
                    for(int j = n-1; j >= 0; j--) {
                        if(order[edges[j][0]] && order[edges[j][1]]) {
                            ans.push_back(edges[j][0]);
                            ans.push_back(edges[j][1]);
                            return ans;
                        }
                    }
                }
            }
        }

        return ans;

    }
};
