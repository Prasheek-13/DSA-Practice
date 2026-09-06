class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<int> detact(n);
        for (int i = 0; i < n; i++) {
            detact[i] = nums1[i] % 2;
        }
        if (detact[0] == 0) {
            int i = 1;
            while (i < n) {
                if (detact[i] == 1) {
                    return false;
                }
                i++;
            }
        } else {
            int j = 1;
            while (j < n) {
                if (detact[j] == 0) {
                    return true;
                }
                j++;
            }
        }
        return true;
    }
};