class Solution {
public:

    int f(int amount, vector<int>& coins, int index, vector<vector<int>>& dp){

        if(amount == 0) return 1;

        if(index == coins.size()) return 0;

        if(dp[index][amount] != -1) return dp[index][amount];

        if(amount < coins[index]) return dp[index][amount] = 0;

        int taken = f(amount - coins[index], coins, index, dp);
        int not_taken = f(amount, coins, index + 1, dp);

        return dp[index][amount] = taken + not_taken;
    }

    int change(int amount, vector<int>& coins) {

        sort(coins.begin(), coins.end());
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return f(amount, coins, 0, dp);

    }
};
