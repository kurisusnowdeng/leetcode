#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int Q = 9973;
public:
	inline int getkey(long long x) {
		return (((x % Q) * (x % Q)) % Q);
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		int N = A.size();
		int f[1000][1000];
		memset(f, 0, sizeof(f));
		vector<int> hash[10000];
		for (int i = 0; i < N; i++) {
			hash[getkey(A[i])].push_back(i);
		}
		for (int i = 1; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int key = getkey((long long)A[i] + A[i] - A[j]);
				for (int k = 0; k < hash[key].size(); k++) {
					int p = hash[key][k];
					if (p >= i) {
						break;
					}
					if ((long long)A[p] + A[j] == (long long)A[i] << 1) {
						f[i][j] = f[i][j] + f[p][i] + 1;
					}
				}
			}
		}

		int ans = 0;
		for (int i = 1; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				ans += f[i][j];
			}
		}

		return ans;
	}
};

int main() {
	Solution test;
	vector<int> A{ 79,20,64,28,67,81,60,58,97,85,92,96,82,89,46,50,15,2,36,44,54,2,90,37,7,79,26,40,34,67,64,28,60,89,46,31,9,95,43,19,47,64,48,95,80,31,47,19,72,99,28,46,13,9,64,4,68,74,50,28,69,94,93,3,80,78,23,80,43,49,77,18,68,28,13,61,34,44,80,70,55,85,0,37,93,40,47,47,45,23,26,74,45,67,34,20,33,71,48,96 };
	int result = test.numberOfArithmeticSlices(A);
	cout << result << endl;
	system("pause");
	return 0;
}