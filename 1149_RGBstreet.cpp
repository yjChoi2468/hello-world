#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, pr = 0, pg = 0, pb = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		r = r + min(pg, pb);
		g = g + min(pb, pr);
		b = b + min(pr, pg);
		pr = r; pg = g; pb = b;
	}
	cout << min(pr, min(pg, pb));
	return 0;
}

/*
dp[1001][3] = { {0, 0, 0} };
dp[i][0] = r + min(dp[i - 1][1], dp[i - 1][2]);
dp[i][1] = g + min(dp[i - 1][2], dp[i - 1][0]);
dp[i][2] = b + min(dp[i - 1][0], dp[i - 1][1]);
*/