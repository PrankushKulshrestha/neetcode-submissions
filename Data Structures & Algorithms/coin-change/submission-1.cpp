class Solution {
public:
    int solve(int i, int target, vector<int>& coins){
        if(target == 0) return 0;
        if(i == 0){
            if(target % coins[0] == 0) return target / coins[0];
            else return 1e9;
        }
        int take = 1e9;
        int not_take = 0;
        if(coins[i] <= target){
            take = 1 + solve(i, target - coins[i], coins);
        }
        not_take = 0 + solve(i - 1, target, coins);

        return min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int ans = solve(n-1, amount, coins);
        if(ans == 1e9) return -1;
        return ans;
    }
};
