#include <iostream>
#include <algorithm>
using namespace std;

int N, M, tree[200000];

int min_val(int l, int r) {
	int ans = 1e9;
	for (l += N - 1, r += N-1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) ans = min(ans, tree[l++]);
		if (~r & 1) ans = min(ans, tree[r--]);
	}
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> tree[N + i];
	for (int i = N - 1; i > 0; i--)
		tree[i] = min(tree[i << 1], tree[(i << 1) | 1]);
	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		cout << min_val(l, r) << '\n';
	}
	return 0;
}