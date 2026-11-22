class Solution {
public:
    bool checkString(string s) {
        bool find = false;
        for (char ch : s) {
            if (ch == 'b') {
                find = true;
            }
        }
        if (!find) {
            return true;
        }
        char target = 'b';
        size_t pos = s.find(target);
        for (size_t i = pos + 1; i < s.size(); i++) {
            if (s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};