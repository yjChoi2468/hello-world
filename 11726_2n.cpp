/*
fibonacci
1000
1115

21
7704
*/

#include <cstdio>

int main(void) {
	int n, a = 1, b = 1;
	scanf("%d", &n);
	while (--n) {
		b = ((a += b) - b) % 10007;
		a %= 10007;
	}
	printf("%d", a);
	return 0;
}