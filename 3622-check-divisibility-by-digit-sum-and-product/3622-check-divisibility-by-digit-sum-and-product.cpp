class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        vector<int> dig;
        while (n > 0) {
            int d = n % 10;
            dig.push_back(d);
            n = n / 10;
        }
        int sum = 0;
        int pro = 1;
        for (int i = 0; i < dig.size(); i++) {
            sum += dig[i];
            pro *= dig[i];
        }
        if (ori % (sum + pro) == 0) {
            return true;
        }
        return false;
    }
};