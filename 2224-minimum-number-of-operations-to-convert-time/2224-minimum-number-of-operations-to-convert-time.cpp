class Solution {
public:
    int conversion(string time) {
        string hrs = time.substr(0, 2);
        string min = time.substr(3, 2);
        int hrsi = stoi(hrs);
        int mini = stoi(min);
        return mini + hrsi * 60;
    }
    int convertTime(string current, string correct) {
        int Tcorrect = conversion(correct);
        int Tcurrent = conversion(current);
        int Treq = Tcorrect - Tcurrent;
        vector<int> Tstamps = {1, 5, 15, 60};
        vector<int> dp(Treq + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= Treq; i++) {
            for (int s : Tstamps) {
                if (i >= s && dp[i - s] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - s]);
                }
            }
        }
        if (dp[Treq] == INT_MAX) {
            return -1;
        }
        return dp[Treq];
    }
};