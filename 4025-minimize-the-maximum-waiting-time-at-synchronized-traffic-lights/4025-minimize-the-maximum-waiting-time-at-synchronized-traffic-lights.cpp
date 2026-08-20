class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        vector<int> ans(n);
        sort(lights.begin(), lights.end());
        int maxlight = lights[lights.size() - 1];

            for (int i = 0; i < n; i++) {
            int r = arrivalTime[i] % period;
            if (r >= maxlight) {
                ans[i] = (period - r);
            } else {
                ans[i] = 0;
            }
        }
        sort(ans.begin(), ans.end());
        return ans[n - 1];
    }
};