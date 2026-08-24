class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd = 0;
        int sumeven = 0;

        for (int i = 2; i <= 2 * n; i = i + 2) {
            sumeven += i;
        }
        for (int i = 1; i <= 2 * n; i = i + 2) {
            sumodd += i;
        }
        return gcd(sumeven, sumodd);
    }
};