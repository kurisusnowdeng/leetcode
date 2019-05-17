class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[300];
        memset(pos, 0, sizeof(pos));
        int left = 1, right = 0, max = 0, idx = 0;
        for (char c : s) {
            idx++;
            right++;
            int i = (int)c;
            left = (pos[i] >= left) ? (pos[i] + 1) : left;
            max = (right - left + 1 > max) ? (right - left + 1) : max;
            pos[i] = idx;
            // cout << left << " " << right << " | ";
            // for (int j = 97; j < 100; j++) {
            //     cout << pos[j] << " ";
            // }
            // cout << endl;
        }
        return max;
    }
};
