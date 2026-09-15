class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int costS = cost.size();
        int top = costS;
        vector<int> results(costS, -1);
        int from0 = dp(results, cost, 0, top);
        return min(results[0], results[1]);
    }

    int dp(vector<int>& r, vector<int>& cost, int curr, int top){
        if(curr >= top){
            return 0;
        }else if(r[curr] != -1){
            return r[curr];
        }else{
            r[curr] = cost[curr] + min(dp(r, cost, curr+1, top), dp(r, cost, curr+2, top));
            return r[curr];
        }
    }
};
