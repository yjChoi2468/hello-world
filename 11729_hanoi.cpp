#include <cstdio>

void dc(int n, int s, int d) {
	if (n == 1) {
		printf("%c %c\n", s + 48, d + 48);
		return;
	}
	dc(n - 1, s, 6 - (s + d));
	printf("%c %c\n", s + 48, d + 48);
	dc(n - 1, 6 - (s + d), d);
	return;
}

int main(void) {
	int N;
	scanf("%d", &N);
	printf("%d\n", (1 << N) - 1);
	dc(N, 1, 3);
	return 0;
}