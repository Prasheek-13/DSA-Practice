class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8) {
            return n;
        } else {
            int mn = n - 8;
            if (mn >= 1 && mn <= 8) {
                return mn * 2 + 8;
            } else if (mn >= 9 && mn <= 16) {
                int a = mn - 8;
                return 24 + a * 3;
            } else if (mn >= 17 && mn <= 24) {
                int b = mn - 16;
                return 48 + b * 4;
            }
        }
        return 0;
    }
};