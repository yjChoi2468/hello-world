// Floyd's Algorithm
#include <iostream>
#include <algorithm>
using namespace std;

int D[105][105], V[105][2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n = n + 1;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= i; j++)
				D[i][j] = D[j][i] = 1e9;
		for (int i = 0; i <= n; i++) {
			cin >> V[i][0] >> V[i][1];
			for (int j = 0; j < i; j++) {
				int dist = abs(V[i][0] - V[j][0]) + abs(V[i][1] - V[j][1]);
				if (dist <= 1000)
					D[i][j] = D[j][i] = 1;
			}
			D[i][i] = 0;
		}

		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= i; j++)
					D[j][i] = D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

		printf("%s\n", (D[0][n] != 1e9 ? "happy" : "sad"));
	}
	return 0;
}