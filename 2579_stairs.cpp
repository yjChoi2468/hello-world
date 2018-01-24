#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int dp[302][2] = { 0, }, n, s;
	scanf("%d", &n);
	for (int i = 2; i < n + 2; i++) {
		scanf("%d", &s);
		dp[i][0] = s + dp[i - 1][1];
		dp[i][1] = s + max(dp[i - 2][0], dp[i - 2][1]);
	}
	printf("%d", max(dp[n + 1][0], dp[n + 1][1]));
	return 0;
}