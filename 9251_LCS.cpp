#include <iostream>
#include <string>
using namespace std;

int lcs[1001][1001];
int main(void) {
	string first, second;
	int n, m;
	getline(cin, first);
	getline(cin, second);
	n = first.size();
	m = second.size();
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
			if (first[i - 1] == second[j - 1] && lcs[i - 1][j - 1] + 1 > lcs[i][j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
		}
	printf("%d", lcs[n][m]);
	return 0;
}