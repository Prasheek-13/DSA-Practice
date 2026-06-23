class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alti(n + 1, 0);
        alti[1] = gain[0];
        for (int i = 2; i <= n; i++) {
            alti[i] = alti[i - 1] + gain[i - 1];
        }
        int ans = INT_MIN;
        for (int i = 0; i < n + 1; i++) {
            ans = max(ans, alti[i]);
        }
        return ans;
    }
};