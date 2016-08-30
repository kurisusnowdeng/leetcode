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
