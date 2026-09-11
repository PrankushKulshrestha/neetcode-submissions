class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using Pair = std::pair<int, int>;
        std::unordered_map<int, std::vector<Pair>> graph;
        for (const auto& x : times) {
            int source = x[0];
            int target = x[1];
            int time = x[2];
            graph[source].emplace_back(target, time);
        }

        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> toProcess;
        toProcess.emplace(0, k);
        std::vector<bool> visited(n);
        int count = n;
        while(!toProcess.empty()) {
            auto [totalTime, node] = toProcess.top();
            toProcess.pop();
            if (visited[node - 1])
                continue;
            visited[node - 1] = true;

            if (--count == 0) {
                return totalTime;
            }

            for (const auto [neighbor, time] : graph[node]) {
                if (!visited[neighbor - 1]) {
                    toProcess.emplace(totalTime + time, neighbor);
                }
            }
        }

        return -1;
    }
};
