class Solution {
public:
    int helper(vector<int>& nums, int target, int n) {

        if (n == 0) {
            return target == 0;
        }

        int plus = helper(nums, target - nums[n - 1], n - 1);
        int minus = helper(nums, target + nums[n - 1], n - 1);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, nums.size());
    }
};