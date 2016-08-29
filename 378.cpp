#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int low = matrix[0][0];
		int high = matrix[n - 1][n - 1] + 1;
		while (low + 1 < high) {
			int mid = (low + high) / 2;
			int sum = 0;
			int j = n - 1;
			for (int i = 0; i < n; i++) {
				while (j >= 0 && matrix[i][j] >= mid) {
					j--;
				}
				sum += j + 1;
			}
			if (sum < k) {
				low = mid;
			}
			else {
				high = mid;
			}
		}
		return low;
	}
};

int main() {
	Solution test;
	int size = 5;
	vector<vector<int>> matrix(size, vector<int>(size));
	int buff[25] = {1, 5, 9, 10, 11, 
					10, 12, 13, 15, 18,
					13, 18, 27, 30, 35,
					20, 32, 33, 36, 42,
					22, 33, 44, 55, 66};
	for (int i = 0; i < size * size; i++) {
		matrix[i / size][i % size] = buff[i];
	}
	cout << test.kthSmallest(matrix, 25) << endl;
	system("pause");
	return 0;
}