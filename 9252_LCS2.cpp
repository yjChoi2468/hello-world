/* 4ms */
#include <cstdio>

int p[1001][1001];
int lcs[2][1001];
int main(void) {
	char s1[1001], s2[1001];
	int m, n;
	scanf("%s %s", s1, s2);
	for (m = 0; s1[m]; m++);
	for (n = 0; s2[n]; n++);
	for (int i = m - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--) {
			if (s1[i] == s2[j]) {
				lcs[i & 1][j] = lcs[1 - i & 1][j + 1] + 1;
				p[i][j] = 1;
			}
			else if(lcs[1 - i & 1][j] > lcs[i & 1][j + 1]){
				lcs[i & 1][j] = lcs[1 - i & 1][j];
				p[i][j] = 2;
			}
			else {
				lcs[i & 1][j] = lcs[i & 1][j + 1];
				p[i][j] = 3;
			}
		}
	printf("%d\n", lcs[0][0]);
	for (int i = 0, j = 0; i < m && j < n;) {
		if (p[i][j] == 1) {
			printf("%c", s1[i]);
			i++; j++;
		}
		else if (p[i][j] == 2)
			i++;
		else if (p[i][j] == 3)
			j++;
	}
	return 0;
}