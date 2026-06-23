class Solution {
public:
    int minLights(vector<int>& lights) {
        int minIdx = -1;
        int maxIdx = -1;
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] != 0) {
                minIdx = max(0, i - lights[i]);
                maxIdx = min(n - 1, i + lights[i]);
                diff[minIdx]++;
                if (maxIdx + 1 < n) {
                    diff[maxIdx + 1]--;
                }
            }
        }
        vector<int> visible(n, 0);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            visible[i] = (cur > 0);
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (visible[i]) {
                i++;
                continue;
            }

            int len = 0;
            while (i < n && !visible[i]) {
                len++;
                i++;
            }
            ans += (len + 2) / 3;
        }
        return ans;
    }
};