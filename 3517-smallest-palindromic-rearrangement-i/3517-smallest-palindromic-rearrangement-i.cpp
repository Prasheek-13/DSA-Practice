class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n % 2 == 0) {
            int m = n / 2;
            string halfstring = "";
            for (int i = 0; i < m; i++) {
                halfstring.push_back(s[i]);
            }
            sort(halfstring.begin(), halfstring.end());
            string rhalfstring = halfstring;
            reverse(rhalfstring.begin(), rhalfstring.end());
            halfstring += rhalfstring;
            return halfstring;
        } else {
            int m = n / 2;
            string halfstring = "";
            for (int i = 0; i < m; i++) {
                halfstring.push_back(s[i]);
            }
            sort(halfstring.begin(), halfstring.end());
            string rhalfstring = halfstring;
            reverse(rhalfstring.begin(), rhalfstring.end());
            return halfstring + s[n / 2] + rhalfstring;
        }
        return "";
    }
};