class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> newnums = nums;

        vector<int> digrange;
        for (int i = 0; i < nums.size(); i++) {
            int smallest = INT_MAX;
            int largest = INT_MIN;
            while (nums[i] > 0) {
                int rem = nums[i] % 10;
                smallest = min(smallest, rem);
                largest = max(largest, rem);
                nums[i] = nums[i] / 10;
            }
            digrange.push_back(largest - smallest);
        }
        int mx = *max_element(digrange.begin(), digrange.end());
        int ans = 0;
        for (int i = 0; i < digrange.size(); i++) {
            if (digrange[i] == mx) {
                ans = ans + newnums[i];
            }
        }
        return ans;
    }
};