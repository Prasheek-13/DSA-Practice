class Solution {
public:
    int smallestNumber(int n, int t) {
        int curr = n;

        for (int i = 0; i < n + 10; i++) {
            int rn = curr;
            int pro = 1;
            while (rn > 0) {
                int d = rn % 10;
                pro = pro * d;
                rn = rn / 10;
            }
            if (pro % t == 0)
                return curr;
            curr++;
        }
        return curr;
    }
};