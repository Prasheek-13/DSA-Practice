class Solution {
public:
    int minOperations(string s) {
        char smallest = s[0];
        char largest = s[0];
        int minCount = 0;
        int maxCount = 0;
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] < smallest) {
                smallest = s[i];
            }
            if (s[i] > largest) {
                largest = s[i];
            }
        }
        string ssort = s;
        sort(ssort.begin(), ssort.end());
        bool istrue = true;
        for (int i = 0; i < s.size(); i++) {
            if (ssort[i] != s[i]) {
                istrue = false;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == smallest)
                minCount++;
            if (s[i] == largest)
                maxCount++;
        }
        if (istrue) {
            return 0;
        }
        if (s.size() == 2 && smallest == s[s.size() - 1]) {
            return -1;
        }
        if (smallest == s[0] || largest == s[s.size() - 1]) {
            return 1;
        }

        if (largest == s[0] && smallest == s[s.size() - 1] && maxCount == 1 &&
            minCount == 1) {

            return 3;
        }
        return 2;
    }
};