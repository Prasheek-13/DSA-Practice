class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> duration = {1, 7, 30};
        vector<int> dp(days.size() + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 3; k++) {
                int expiry = days[i] + duration[k];
                int j = i;
                while (j < n && days[j] < expiry) {
                    j++;
                }
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }
        if (dp[0] == INT_MAX) {
            return -1;
        }
        return dp[0];
    }
};