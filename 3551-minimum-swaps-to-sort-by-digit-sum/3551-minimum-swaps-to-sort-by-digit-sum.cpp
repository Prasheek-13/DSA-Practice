class Solution {
public:
    int digsum(int num) {
        int sum = 0;
        num = abs(num);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> pairdigsum;
        for (int i = 0; i < n; i++) {
            pairdigsum.push_back({digsum(nums[i]), nums[i], i});
        }
        sort(pairdigsum.begin(), pairdigsum.end());
        vector<int> vis(n, 0);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(pairdigsum[i]) == i) {
                continue;
            }

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = 1;
                j = get<2>(pairdigsum[j]);
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};