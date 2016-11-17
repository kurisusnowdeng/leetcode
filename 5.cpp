class Solution {
public:
    string longestPalindrome(string s) {
        int len = 2 * s.length() + 1;
        int *a = new int[len];
        int *f = new int[len];
        a[0] = 0;
        for (int i = 0; i < s.length(); i++) {
            a[i + i + 1] = (int)s[i];
            a[i + i + 2] = 0;
        }
        int max = 0;
        int pos = 0;
        f[0] = 0;
        for (int i = 1; i < len; i++) {
            int l = 0;
            if (i <= max) {
                l = f[pos + pos - i];
                if (i + l > max) {
                    l = max - i;
                }
            }
            while (i + l + 1 < len && i - l - 1 >= 0 
                    && a[i + l + 1] == a[i - l - 1]) {
                l++;
            }
            f[i] = l;
            if (i + l > max) {
                max  = i + l;
                pos = i;
            }
        }
        max = 0;
        pos = 0;
        for (int i = 0; i < len; i++) {
            if (f[i] > max) {
                max = f[i];
                pos = i;
            }
        }
        string res = "";
        for (int i = pos - max; i <= pos + max; i++) {
            if (a[i] > 0) {
                res += (char)a[i];
            }
        }
        return res;
    }
};
