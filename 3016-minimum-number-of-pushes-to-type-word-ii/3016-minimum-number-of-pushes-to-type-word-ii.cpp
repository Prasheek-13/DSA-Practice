class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int pushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                break;
            }
            int position = i / 8 + 1;
            pushes += position * freq[i];
        }
        return pushes;
    }
};