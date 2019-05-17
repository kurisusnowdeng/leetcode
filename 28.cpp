class Solution {
public:
    
void getNext(string p, vector<int> &next) {
	next[0] = 0;
	int j = 0;
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[i] != p[j])
			j = next[j - 1];
		if (p[i] == p[j])
			++j;
		next[i] = j;
	}
}

int strStr(string haystack, string needle) {
	if (needle.length() == 0) return 0;
	vector<int> next(needle.length());
	getNext(needle, next);
	int j = 0;
	int pos = -1;
	for (int i = 0; i < haystack.length(); i++) {
		while (j > 0 && needle[j] != haystack[i])
			j = next[j - 1];
		if (needle[j] == haystack[i])
			++j;
		if (j == needle.length()) {
			pos = i - needle.length() + 1;
			break;
		}
	}
	return pos;
}

};
