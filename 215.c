#include <stdio.h>
#include <stdlib.h>

void _sort(int *arr, int k, int low, int high) {
	if (high < k || low > k) return;
	int pivot = arr[(low + high) / 2];
	int i = low;
	int j = high;
	int temp;
	while (i <= j) {
		while (arr[i] > pivot) ++i;
		while (arr[j] < pivot) --j;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}
	}
	if (low < j) _sort(arr, k, low, j);
	if (i < high) _sort(arr, k, i, high);
}

int findKthLargest(int* nums, int numsSize, int k) {
	_sort(nums, k - 1, 0, numsSize - 1);
	return nums[k - 1];
}

int main() {
	int nums[6] = { 3,2,1,5,6,4 };
	int numsSize = 6;
	int k = 2;
	printf("%d\n", findKthLargest(nums, numsSize, k));
	system("pause");
	return 0;
}