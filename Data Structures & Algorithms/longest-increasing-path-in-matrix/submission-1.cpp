class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        map<pair<int,int>,vector<pair<int,int>>> graph;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                graph[{i,j}] = vector<pair<int,int>>{};
                for(auto k:dirs){
                    int x = i+k[0];
                    int y = j+k[1];
                    if(x < 0 || y < 0 || x >= n || y >= m) continue ;
                    if(matrix[i][j] >= matrix[x][y]) continue ;
                    graph[{i,j}].push_back({x,y});
                }
            }
        }

        int answer = 0 ;
        map<pair<int,int>,int> dist;
        for(auto node:graph){
            if(dist.find(node.first) != dist.end()) continue ;
            dist[node.first] = 1 ;
            answer = max(answer, dist[node.first]);

            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq ;
            pq.push({matrix[node.first.first][node.first.second], node.first.first, node.first.second});

            while(!pq.empty()){
                auto u = pq.top();
                pq.pop();

                for(auto k: graph[{get<1>(u),get<2>(u)}]){
                    if(dist.find(k) == dist.end()) dist[k] = 1 ;
                    if(dist[k] >= dist[{get<1>(u),get<2>(u)}] + 1) continue;

                    pq.push({matrix[k.first][k.second],k.first, k.second});
                    dist[k] = dist[{get<1>(u),get<2>(u)}] + 1;
                     answer = max(answer, dist[k]);
                }
            }
        }
        return answer ;
    }
};
