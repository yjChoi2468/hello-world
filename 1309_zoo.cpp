#include <cstdio>

int main(void) {
	int n, a = 1, b = 1;
	scanf("%d", &n);
	while (n--) {
		b = (2 * a + b) % 9901;
		a = (b - a + 9901) % 9901;
	}
	printf("%d", b);
	return 0;
}