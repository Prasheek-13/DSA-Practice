class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int i = 0;
        while (i < nums.size()) {
            vector<int> prefix(nums.begin(), nums.begin() + i + 1);
            vector<int> suffix(nums.begin() + i, nums.end());
            sort(prefix.begin(), prefix.end());
            sort(suffix.begin(), suffix.end());
            int ans;
            if (i == 0) {
                ans = nums[0] - suffix[0];
            } else {
                ans = prefix[prefix.size() - 1] - suffix[0];
            }
            if (ans <= k) {
                return i;
            }
            i++;
        }

        return -1;
    }
};