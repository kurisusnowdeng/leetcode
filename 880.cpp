class Solution {
public:
    string str = "";
    
    char getChar(int tail, long long len, int loc) {
        // printf("%d %ld %d\n", tail, len, loc);
        char x = str[tail];
        if (x >= '2' && x <= '9') {
            int n = x - '0';
            return getChar(tail - 1, len / n, ((loc - 1) % (len / n)) + 1);
        }
        else {
            if (len == loc) return x;
            return getChar(tail - 1, len -1 , loc);
        }
    }
    
    string decodeAtIndex(string S, int K) {
        str = S;
        long long len = 0;
        int tail = 0;
        for (int i = 0; i < str.length(); i++) {
            char x = str[i];
            if (x >= '2' && x <= '9') {
                len *= x - '0';
            }
            else {
                len++;
            }
            if (len >= K) {
                tail = i;
                break;
            }
        }
        string ans(1, getChar(tail, len, K));
        return ans;
    }
};
