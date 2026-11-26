class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        dp[0][1000] = 1;
        for (int i = 0; i < n; i++) {
            for (int s = -1000; s <= 1000; s++) {
                if (dp[i][s + 1000] > 0) {
                    dp[i + 1][s + nums[i] + 1000] += dp[i][s + 1000];
                    dp[i + 1][s - nums[i] + 1000] += dp[i][s + 1000];
                }
            }
        }
        return dp[n][target + 1000];
    }
};