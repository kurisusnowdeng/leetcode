#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
	int hash[128];
	map<char, int> pattern;

	void init(string t) {
		pattern.clear();
		for (int i = 0; i < t.length(); i++) {
			if (pattern.find(t[i]) != pattern.end()) {
				pattern[t[i]] = pattern[t[i]] + 1;
			}
			else {
				pattern.insert(map<char, int>::value_type(t[i], 1));
			}
		}
	}

	bool count() {
		bool check = true;
		for (map<char, int>::iterator it = pattern.begin(); it != pattern.end(); it++) {
			if (it->second > hash[(it->first) - 65]) {
				check = false;
				break;
			}
		}
		return check;
	}

public:
	string minWindow(string s, string t) {
		int left = -1;
		int right = 0x7ffffffE;
		memset(hash, 0, sizeof(hash));
		init(t);
		int i = 0;
		int j = -1;
		bool check = false;
		int last = s.length() - 1;
		while (j < last) {
			while (j < last && !check) {
				j++;
				hash[s[j] - 65]++;
				check = count();
			}
			while (i <= j && check) {
				if ((j - i) < (right - left)) {
					left = i; right = j;
				}
				hash[s[i] - 65]--;
				i++;
				check = count();
			}
		}
		if (left >= 0) {
			return s.substr(left, right - left + 1);
		}
		else return "";
	}
};

int main() {
	Solution test;
	cout << test.minWindow("abcaaccbacabbbbbbcbaacbcabcca", "abbbbbbaacbbbccccabbc") << endl;
	system("pause");
	return 0;
}