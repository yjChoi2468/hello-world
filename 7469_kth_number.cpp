#include <iostream>
#include <algorithm>
using namespace std;

struct Arr{
	int num, idx;
	bool operator < (const Arr& b) const {
		return this->num < b.num;
	}
};

int n, m, i, j, k, it;
Arr arr[100000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (it = 0; it < n; it++) {
		int tmp;
		cin >> arr[it].num;
		arr[it].idx = it + 1;
	}
	sort(arr, arr + n);
	while (m--) {
		int cnt = 0;
		cin >> i >> j >> k;
		for (it = 0; it < n; it++) {
			if (arr[it].idx >= i && arr[it].idx <= j)
				if (++cnt == k)
					break;
		}
		cout << arr[it].num << '\n';
	}
	return 0;
}



#include<bits/stdc++.h>
using namespace std;

namespace wtree
{
	const int MAXN = 100000 * 2;
	const int INF = 0x3f3f3f3f;
	int sz[MAXN];
	int* wavelet[MAXN];
	int* leftsum[MAXN];
	int lc[MAXN]; //left child 
	int rc[MAXN]; //right child 
	int sr[MAXN]; //start range 
	int er[MAXN]; //end range
	int tp = 0;
	void build(int x)
	{
		int s = sr[x], e = er[x], m = s + e >> 1, N = sz[x], ls = 0;
		lc[x] = rc[x] = -1;
		leftsum[x] = (int*)malloc(sizeof(int)*(N + 1));
		leftsum[x][0] = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (wavelet[x][i] <= m) ++ls;
			leftsum[x][i] = ls;
		}
		if (s == e) return;

		lc[x] = tp; sr[tp] = er[tp] = s; sz[tp] = ls;
		wavelet[tp] = (int*)malloc(sizeof(int)*sz[tp]) - 1;
		tp++;
		rc[x] = tp; sr[tp] = er[tp] = e; sz[tp] = N - ls;
		wavelet[tp] = (int*)malloc(sizeof(int)*sz[tp]) - 1;
		tp++;

		int ind1 = 0, ind2 = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (wavelet[x][i] <= m)
			{
				wavelet[lc[x]][++ind1] = wavelet[x][i];
				er[lc[x]] = max(er[lc[x]], wavelet[x][i]);
			}
			else
			{
				wavelet[rc[x]][++ind2] = wavelet[x][i];
				sr[rc[x]] = min(sr[rc[x]], wavelet[x][i]);
			}
		}
		build(lc[x]); build(rc[x]);
		free(wavelet[x] + 1);
		return;
	}
	int getKth(int s, int e, int k, int idx = 0)
	{
		if (sr[idx] == er[idx]) return sr[idx];
		int lcount = leftsum[idx][e] - leftsum[idx][s - 1];
		if (k <= lcount)
			return getKth(leftsum[idx][s - 1] + 1, leftsum[idx][e], k, lc[idx]);
		else
			return getKth(s - leftsum[idx][s - 1], e - leftsum[idx][e], k - lcount, rc[idx]);
	}
}
using namespace wtree;
int N, M;
int main()
{
	scanf("%d%d", &N, &M);
	sz[tp] = N;
	wavelet[tp] = (int*)malloc(sizeof(int)*N) - 1;
	sr[tp] = INF;
	er[tp] = -INF;
	for (int i = 1; i <= N; ++i)
	{
		int t;
		scanf("%d", &t);
		wavelet[tp][i] = t;
		sr[tp] = min(sr[tp], t);
		er[tp] = max(er[tp], t);
	}
	build(tp++);
	for (int i = 0; i<M; ++i)
	{
		int s, e, k;
		scanf("%d%d%d", &s, &e, &k);
		printf("%d\n", getKth(s, e, k));
	}
	return 0;
}