#include <cstdio>

#define MOD 1000000000

int main(void) {
	int n, cnt = 0, dp[2][10] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) dp[n & 1][i] = dp[1 - n & 1][i] = 1;
	for (int i = n - 1; i > 0; i--) {
		dp[1 - i & 1][0] = dp[i & 1][1];
		dp[1 - i & 1][9] = dp[i & 1][8];
		for (int j = 1; j < 9; j++)
			dp[1 - i & 1][j] = (dp[i & 1][j - 1] + dp[i & 1][j + 1]) % MOD;
	}
	for (int i = 0; i < 10; i++) cnt = (cnt + dp[0][i]) % MOD;
	printf("%d", cnt);
	return 0;
}