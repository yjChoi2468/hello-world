#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Adj {
	int u, v, w;
	Adj() {}
	bool operator < (const Adj &b) const {
		return w < b.w;
	}
};

int p[100000];

int find(int c) {
	if (c == p[c]) return c;
	return p[c] = find(p[c]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, res = 0;
	cin >> N >> M;
	vector<Adj> adj(M);
	for (int i = 0; i < N; i++) p[i] = i;
	for (int i = 0; i < M; i++)
		cin >> adj[i].u >> adj[i].v >> adj[i].w;
	sort(adj.begin(), adj.end());
	for (int i = 0; N > 2; i++) {
		int uroot = find(adj[i].u), vroot = find(adj[i].v);
		if (uroot != vroot) {
			p[vroot] = uroot;
			res += adj[i].w;
			N--;
		}
	}
	/*
	for (auto e : adj) {
		int uroot = find(e.u), vroot = find(e.v);
		if (uroot != vroot) {
			p[vroot] = uroot;
			res += e.w;
			mx = max(res, e.w);
		}
	}
	cout << res - mx;
	*/
	cout << res;
	return 0;
}