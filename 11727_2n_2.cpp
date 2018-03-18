/*
4
11

8
171

12
2731
*/

#include <cstdio>

int main(void) {
	int n, a = 1, b = 1;
	scanf("%d", &n);
	while (--n) {
		b = ((a += (b << 1)) - (b << 1)) % 10007;
		a %= 10007;
	}
	printf("%d", a);
	return 0;
}