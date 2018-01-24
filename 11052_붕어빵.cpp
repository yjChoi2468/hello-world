#include <cstdio>
using namespace std;

int main(void) {
	int n, p, dp[1001] = { 0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p);
		for (int j = i; j <= n; j++)
			if (dp[j - i] + p > dp[j])
				dp[j] = dp[j - i] + p;
	}
	printf("%d", dp[n]);
	return 0;
}