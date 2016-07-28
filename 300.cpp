#include <iostream>

using namespace std;

int lengthOfLIS(int* nums, int numsSize) {
	int *f = (int *)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		f[i] = 0;
		int max = 0;
		int k = -1;
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				if (f[j] > max) {
					max = f[j];
					k = j;
				}
			}
		}
		f[i] = max + 1;
	}
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		if (f[i] > ans)
			ans = f[i];
	}
	free(f);
	f = NULL;
	return ans;
}

int main() {
	//int a[10] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int a[20] = { 13, 7, 9, 16, 38, 24, 37, 18, 44, 19, 21, 22, 63, 15 };
	cout << lengthOfLIS(a, 14) << endl;
	system("pause");
}