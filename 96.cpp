#include <iostream>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int *f = new int[n + 1];
		memset(f, 0, sizeof(int) * (n + 1));
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				f[i] += f[j] * f[i - 1 - j];
			}
		}
		return f[n];
	}
};

int main() {
	Solution test;
	cout << test.numTrees(12) << endl;
	system("pause");
	return 0;
}