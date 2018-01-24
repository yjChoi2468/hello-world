#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int dp[501][501] = { 0, }, n, mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	for (int i = 1; i <= n; i++)
		mx = max(mx, dp[n][i]);
	cout << mx;
	return 0;
}