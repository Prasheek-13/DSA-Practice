class Solution {
public:
    int helper(int st, int end, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n - 1);
        dp[0] = nums[st];
        dp[1] = max(nums[st + 1], nums[st]);
        for (int i = st + 2, j = 2; i <= end; i++, j++) {
            dp[j] = max(nums[i] + dp[j - 2], dp[j - 1]);
        }
        return dp[n - 2];
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