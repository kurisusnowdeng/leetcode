class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256];
        memset(hash, 0, sizeof(hash));
        int len = s.length();
        for (int i = 0; i < len; i++) {
            hash[(int)s[i]]++;
        }
        int sum = 0;
        bool find_odd = false;
        for (int i = 65; i < 123; i++) {
            if (hash[i] % 2 > 0) {
                sum += hash[i] - 1;
                find_odd = true;
            }
            else {
                sum += hash[i];
            }
        }
        if (find_odd)
            sum++;
        return sum;
    }
};
