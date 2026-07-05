class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string> substrings;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += word[j];
                substrings.insert(temp);
            }
        }
        int cnt = 0;
        for (int i = 0; i < patterns.size(); i++) {
            if (substrings.find(patterns[i]) != substrings.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};