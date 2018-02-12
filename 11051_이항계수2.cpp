#include <iostream>
using namespace std;

#define MOD(x) (x % 10007)

int main(void) {
	ios_base::sync_with_stdio(false);
	int n, k, con[2][1002] = { 0, 1, 1, 0, };
	cin >> n >> k;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= i + 2; j++)
			con[i & 1][j] = MOD(con[1 - i & 1][j - 1] + con[1 - i & 1][j]);
	cout << con[(n - 1) & 1][k + 1];
	return 0;
}