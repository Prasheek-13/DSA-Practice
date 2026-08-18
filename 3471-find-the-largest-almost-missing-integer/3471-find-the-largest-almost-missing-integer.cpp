class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> ori = nums;
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        if (k == 1) {
            sort(nums.begin(), nums.end());
            int idx = n - 1;
            while (idx >= 0) {

                if (freq[nums[idx]] == 1) {
                    return nums[idx];
                } else {
                    idx--;
                }
            }
        } else if (k == n) {
            sort(nums.begin(), nums.end());
            return nums[n - 1];
        } else {
             if (freq[ori[0]] != 1 && freq[ori[n - 1]] != 1) {
                return -1;
            }
            if (freq[ori[0]] != 1) {
                return ori[n - 1];
            }
            if (freq[ori[n - 1]] != 1) {
                return ori[0];
            }
           
            return max(ori[0], ori[n - 1]);
        }
        return -1;
    }
};