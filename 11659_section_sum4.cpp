#include <iostream>
using namespace std;
/*
int tree[200000], N, M, l, r;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> tree[i + N];
	for (int i = N - 1; i >= 0; i--)
		tree[i] = tree[i << 1] + tree[(i << 1) | 1];
	for (int i = 0; i < M; i++) {
		int ans = 0;
		cin >> l >> r;
		for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ans += tree[l++];
			if (~r & 1) ans += tree[r--];
		}
		cout << ans << '\n';
	}
	return 0;
}
*/
int sum[100001], N, M, l, r;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	for (int i = 0; i < M; i++) {
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << '\n';
	}
	return 0;
}
