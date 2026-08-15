class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int total_xor = 0;

        for (int num : nums) {
            total_xor ^= num;
        }
        if (total_xor != 0) {
            return nums.size();
        }
        for (int x : nums) {
            if (x != 0) {
                return nums.size() - 1;
            }
        }

        return 0;
    }
};