class Solution {
public:
    int helper(string& text1, string& text2, int i, int j,
               vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();
        if (i == n || j == m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1, dp);
        }
        return dp[i][j] = max(helper(text1, text2, i + 1, j, dp),
                              helper(text1, text2, i, j + 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, 0, 0, dp);
    }
};