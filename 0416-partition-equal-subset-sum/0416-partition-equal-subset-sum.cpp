class Solution {
public:
    bool solve(vector<int>& nums, int i, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (i == 0)
            return false;
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        bool nottake = solve(nums, i - 1, target, dp);
        bool take = false;
        if (nums[i - 1] <= target) {
            take = solve(nums, i - 1, target - nums[i - 1], dp);
        }
        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        return solve(nums, nums.size(), target, dp);
    }
};