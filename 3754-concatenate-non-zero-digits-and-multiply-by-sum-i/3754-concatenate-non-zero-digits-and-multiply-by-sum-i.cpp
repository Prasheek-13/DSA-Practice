class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> x;
        long long X = 0;
        long long sum = 0;
        while (n > 0) {
            int rem = n % 10;
            if (rem != 0) {
                x.push_back(rem);
            }
            sum = rem + sum;
            n = n / 10;
        }
        for (int i = 0; i < x.size(); i++) {
            X = X + x[i] * pow(10, i);
        }
        long long ans = X * sum;
        return ans;
    }
};