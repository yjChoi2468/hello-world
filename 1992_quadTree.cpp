#include <cstdio>

char arr[65][65]; // arr[64][65]
int p = 0;
//int dir[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };

void dnc(int n, int x, int y) {
	if (n == 1) {
		putchar(arr[x][y]);
		return;
	}
	char val = arr[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (val != arr[i][j]) {
				n /= 2;
				putchar('(');
				dnc(n, x, y);
				dnc(n, x, y + n);
				dnc(n, x + n, y);
				dnc(n, x + n, y + n);
				/*
				for(int k = 0; k < 4; k++)
					dnc(n, x + n * dir[k][0], y + n * dir[k][1]);
				*/
				putchar(')');
				return;
			}
	putchar(val);
	return;
}

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]);
	dnc(N, 0, 0);
	return 0;
}