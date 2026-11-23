class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i >= c && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};