/*
6
10 10 1 1 10 10
->40

7
10 10 1 1 1 10 10
->41

3
3 2 1
5
*/

#include <cstdio>

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, w, dp[4][2] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n + 3; i++) {
		i < n ? scanf("%d", &w) : w = 0;
		dp[i % 4][0] = w + dp[(i + 3) % 4][1];
		dp[i % 4][1] = w + max(max(dp[(i + 2) % 4][0], dp[(i + 2) % 4][1]), max(dp[(i + 1) % 4][0], dp[(i + 1) % 4][1]));
	}
	printf("%d", dp[(n + 2) % 4][0]);
	return 0;
}