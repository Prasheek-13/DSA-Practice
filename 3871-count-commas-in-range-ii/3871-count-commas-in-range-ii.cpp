class Solution {
public:
    long long countCommas(long long n) {
        long long sum = 0;
        if (n < 1000) {
            sum = 0;
        }
        if (1000 <= n && n < 1000000) {
            sum = n - 999;
        } else if (1000000 <= n && n < 1000000000) {
            sum = 2 * n - 999 - 999999;
        } else if (1000000000 <= n && n < 1000000000000) {
            sum = 3 * n - 999 - 999999 - 999999999;
        } else if (1000000000000 <= n && n < 1000000000000000) {
            sum = 4 * n - 999 - 999999 - 999999999 - 999999999999;
        } else if (n == 1000000000000000) {
            sum = 3998998998999005;
        }

        return sum;
    }
};