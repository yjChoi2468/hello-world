/*
matrix
(1 1) (fn+1   fn)
(1 0) (fn   fn-1)
*/

#include <cstdio>

#define MOD 1000000

int main(void) {
	long long a = 0, b = 1, c = 1, n;
	scanf("%lld", &n);
	n = n % 1500000;
	for (long long i = 1; i < n; i++) {
		c = (a + b) % MOD;
		a = b;
		b = c;
	}
	printf("%lld\n", c);
	return 0;
}