class Solution {
public:
    int helper(int st, int end, vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n - 1);
        // dp[0] = nums[st];
        // dp[1] = max(nums[st + 1], nums[st]);
        int prev2 = nums[st];
        int prev1 = max(nums[st + 1], nums[st]);
        int result = prev1;

        for (int i = st + 2; i <= end; i++) {
            result = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int ans1 = helper(0, n - 2, nums);
        int ans2 = helper(1, n - 1, nums);
        return max(ans1, ans2);
    }
};