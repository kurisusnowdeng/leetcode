int jump(int A[], int n) {
	if (n < 2)
		return 0;
	int level = 0, currentMax = 0, i = 0, nextMax = 0;

	while (currentMax - i + 1 > 0) {
		level++;
		for (; i <= currentMax; i++) {
			nextMax = nextMax > A[i] + i ? nextMax : A[i] + i;
			if (nextMax >= n - 1)
				return level;
		}
		currentMax = nextMax;
	}
	return 0;
}
