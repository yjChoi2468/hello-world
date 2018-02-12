#include <iostream>
#include <algorithm>
using namespace std;

int N, K, tree[200000];
int a, b;
char c;

void update(int i, int v) {
	if (v > 0) v = 1;
	else if (v < 0) v = -1;
	else v = 0;
	if (tree[i += N - 1] != v)
		for (tree[i] = v; i > 1; i >>= 1)
			tree[i >> 1] = tree[i] * tree[i ^ 1];
	return;
}

char mul(int l, int r) {
	int ans = 1;
	for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
		if (ans == 0) break;
		if (l & 1) ans *= tree[l++];
		if (~r & 1) ans *= tree[r--];
	}
	if (ans > 0) return '+';
	if (ans < 0) return '-';
	return '0';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	while (!cin.fail()) {
		for (int i = 0; i < N; i++) {
			cin >> a;
			if (a > 0) tree[N + i] = 1;
			else if (a < 0) tree[N + i] = -1;
			else tree[N + i] = 0;
		}
		for (int i = N - 1; i > 0; i--)
			tree[i] = tree[i << 1] * tree[(i << 1) | 1];
		for (int i = 0; i < K; i++) {
			cin >> c >> a >> b;
			if (c == 'C')
				update(a, b);
			else // c == 'P'
				cout << mul(a, b);
		}
		cout << '\n';
		cin >> N >> K;
	}
	return 0;
}

/*
18 10
8 2 10 8 -8 1 -8 -10 -9 8 6 7 -3 2 6 -3 1 -6
P 12 15
P 5 13
P 5 7
C 4 -4
P 7 16
P 9 17
P 3 4
P 12 16
C 18 6
P 1 18
14 9
-4 -4 -4 7 8 -4 -3 1 2 2 -5 -10 -5 -9
P 5 9
P 5 8
P 8 10
C 2 -6
P 9 13
C 1 9
C 14 10
P 2 4
P 1 14
--+---+-
+++-+-
*/