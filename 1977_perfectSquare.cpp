
#include <stdio.h>

int main(void) {
	int i, j, m, n, p = 100, res = 0, min = 0;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++)
		for (j = 1; j * j <= i; j++)
			if (j * j == i) {
				p = j;
				res += min = i;
				i = j = n;
			}
	for (i = p + 1; i * i <= n; i++)
		res += i * i;
	res != 0 ? printf("%d\n%d", res, min) : printf("-1");
	return 0;
}
/*
#include <stdio.h>

int main(void) {
	int i, j, m, n, p = 100, res = 0, min = 0;
	scanf("%d %d", &m, &n);
	for (i = n; i >= m; i--)
		for (j = p; j * j >= i; j--)
			if (j * j == i) {
				p = j;
				res += min = i;
			}
	res != 0 ? printf("%d\n%d", res, min) : printf("-1");
	return 0;
}
*/
