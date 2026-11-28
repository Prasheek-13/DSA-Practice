class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        int cnt = 0;

        for (int i = 10; i >= 1 && n >= i; i--) {
            n = n - i;
            cnt++;
        }

        if (cnt % 2 == 0) {
            return false;
        }
        return true;
    }
};