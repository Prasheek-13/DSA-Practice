class Solution {
public:
    int helper(vector<int>& nums, int target, int n, vector<vector<int>>& dp) {

        if (n == 0) {
            return target == 0;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (abs(target) > sum)
            return 0;
        if (dp[n - 1][target + 1000] != -1) {
            return dp[n - 1][target + 1000];
        }

        int plus = helper(nums, target - nums[n - 1], n - 1, dp);
        int minus = helper(nums, target + nums[n - 1], n - 1, dp);
        return dp[n - 1][target + 1000] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2001, -1));

        return helper(nums, target, nums.size(), dp);
    }
};