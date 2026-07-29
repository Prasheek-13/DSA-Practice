class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;
        while (n > 0) {
            int dig = n % 10;
            num.push_back(dig);
            n = n / 10;
        }
        sort(num.begin(), num.end());
        int m = num.size();
        int ans = num[m - 1] * num[m - 2];
        return ans;
    }
};