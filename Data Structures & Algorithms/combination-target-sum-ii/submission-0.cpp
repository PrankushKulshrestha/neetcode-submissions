class Solution {
public:
    void dfs(
        vector<vector<int>>& res,
        vector<int>& candidates,
        int target,
        vector<int>& temp,
        int index
    ) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            dfs(
                res,
                candidates,
                target - candidates[i],
                temp,
                i + 1
            );
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target
    ) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res, candidates, target, temp, 0);
        return res;
    }
};
