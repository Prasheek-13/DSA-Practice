class Solution {
public:
    int helper(int i, vector<int>& cost, vector<int>& dp) {
        if (i <= 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int left = helper(i - 1, cost, dp) + cost[i - 1];
        int right = helper(i - 2, cost, dp) + cost[i - 2];
        return dp[i] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return helper(n, cost, dp);
    }
};