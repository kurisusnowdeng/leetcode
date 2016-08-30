#include <stdio.h>
#include <stdlib.h>

#define P 999983

typedef struct _map {
	int value;
	int cnt;
};

void find(int* hash, struct _map *arr, int *n, int x, int q) {
	int key = x % q;
	key = (key * key) % q;
	while (hash[key] >= 0 && arr[hash[key]].value != x) {
		key = (key + 1) % q;
	}
	if (hash[key] < 0) {
		arr[*n].value = x;
		arr[*n].cnt = 1;
		hash[key] = *n;
		(*n)++;
	}
	else {
		arr[hash[key]].cnt++;
	}
}

void sort(struct _map *arr, int k, int low, int high) {
	if (high < k || low > k) return;
	int pivot = arr[(low + high) / 2].cnt;
	int i = low;
	int j = high;
	struct _map temp;
	while (i <= j) {
		while (arr[i].cnt > pivot) ++i;
		while (arr[j].cnt < pivot) --j;
		if (i <= j) {
			temp.value = arr[i].value;
			temp.cnt = arr[i].cnt;
			arr[i].value = arr[j].value;
			arr[i].cnt = arr[j].cnt;
			arr[j].value = temp.value;
			arr[j].cnt = temp.cnt;
			++i;
			--j;
		}
	}
	if (low < j) sort(arr, k, low, j);
	if (i < high) sort(arr, k, i, high);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	int *ans = (int*)malloc(sizeof(int) * (*returnSize));
	memset(ans, 0, sizeof(int) * (*returnSize));
	int hashlen = P;
	if (hashlen < nums.size()) {
	    hashlen = (nums.size() << 1) - 1;
	}
	int *hash = (int*)malloc(sizeof(int) * hashlen);
    memset(hash, 0xff, sizeof(int) * hashlen);
    int n = 0;
    struct _map *arr = (struct _map *)malloc(sizeof(struct _map) * nums.size());
    memset(arr, 0, sizeof(struct _map) * nums.size());
    for (int i = 0; i < nums.size(); i++) {
    	find(hash, arr, &n, nums[i], hashlen);
    }
    free(hash);
	sort(arr, k - 1, 0, n - 1);
	for (int i = 0; i < k; i++) {
		ans[i] = arr[i].value;
	}
	free(arr);
	return ans;
}

int main() {
	int nums[5] = { 1,1,2,2,3 };
	int *ans;
	int returnSize = 3;
	ans = topKFrequent(nums, 5, 2, &returnSize);
	return 0;
}
