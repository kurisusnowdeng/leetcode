class Solution {
public:
    
long long countDigitOne(int n) {
	long long sum = 0;
	for (long long i = 1; i <= n; i *= 10) {
		long long a = n / i;
		long long b = n % i;
		sum += ((a + 8) / 10) * i;
		if (a % 10 == 1) {
			sum += b + 1;
		}
	}
	return sum;
}

};
