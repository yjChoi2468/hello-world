#include <iostream>
#include <algorithm>
using namespace std;

int N, M, mnt[200000], mxt[200000];
int a, b;

void calc(int l, int r, int &mn, int &mx) {
	for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			mn = min(mn, mnt[l]);
			mx = max(mx, mxt[l++]);
		}
		if (~r & 1) {
			mn = min(mn, mnt[r]);
			mx = max(mx, mxt[r--]);
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> mnt[N + i];
		mxt[N + i] = mnt[N + i];
	}
	for (int i = N - 1; i > 0; i--) {
		mnt[i] = min(mnt[i << 1], mnt[(i << 1) | 1]);
		mxt[i] = max(mxt[i << 1], mxt[(i << 1) | 1]);
	}
	for (int i = 0; i < M; i++) {
		int mn = 1e9, mx = 0;
		cin >> a >> b;
		calc(a, b, mn, mx);
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}