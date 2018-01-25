/*
testcase
n m
-> n * m - 1
*/

#include <iostream>
using namespace std;

int choco[301][301];
int main(void) {
	ios_base::sync_with_stdio(false);
	int n, m, tmp;
	cin >> n >> m;
	if (n < m) {
		tmp = n; n = m; m = tmp;
	}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= m; j++)
			choco[i][j] = choco[j][i] = 1 + choco[(i >> 1) + (i & 1)][j] + choco[i >> 1][j];
	cout << choco[n][m];
	return 0;
}