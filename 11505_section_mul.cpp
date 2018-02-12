#include <iostream>
using namespace std;

#define MOD(x) ((x) % 1000000007)
typedef long long ll;

ll tree[2000000], ans = 1L;
int N, M, K, a, b, c;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> tree[N + i];
	for (int i = N - 1; i >= 0; i--) /* build */
		tree[i] = MOD(tree[i << 1] * tree[(i << 1) | 1]);
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) { /* update */
			for (tree[b += N - 1] = c; b > 1; b >>= 1)
				tree[b >> 1] = MOD(tree[b] * tree[b ^ 1]);
		}
		else { /* mul */
			ans = 1L;
			for (b += N - 1, c += N - 1; b <= c; b >>= 1, c >>= 1) {
				if (b & 1) ans = MOD(ans * tree[b++]);
				if (~c & 1) ans = MOD(ans * tree[c--]);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
