class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        int x = 2;
        while (x < nums.size()) {
            int nums1_back = nums1.back();
            int nums2_back = nums2.back();
            if (nums1_back > nums2_back) {
                nums1.push_back(nums[x]);
                x++;
            } else {
                nums2.push_back(nums[x]);
                x++;
            }
        }
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        return nums1;
    }
};