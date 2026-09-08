class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre_map(numCourses);
        for (const auto& p : prerequisites) {
            pre_map[p[0]].push_back(p[1]);
        }
        vector<int> visit_state(numCourses, 0);
        auto dfs = [&](auto& self, int course) -> bool {
            if (visit_state[course] == 1) return false;
            if (visit_state[course] == 2) return true;
            visit_state[course] = 1;
            for (int pre : pre_map[course]) {
                if (!self(self, pre)) return false;
            }
            visit_state[course] = 2;
            return true;
        };
        for (int c = 0; c < numCourses; ++c) {
            if (!dfs(dfs, c)) return false;
        }
        return true;
    }
};