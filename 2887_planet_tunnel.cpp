#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Planet {
	int x, y, z;
	Planet() {}
	int operator - (const Planet &b) const {
		return min(abs(x - b.x), min(abs(y - b.y), abs(z - b.z)));
	}
};

struct Adj {
	int u, v, w;
	Adj(int a, int b, int c) :u(a), v(b), w(c) {}
	bool operator < (const Adj &b) const {
		return w < b.w;
	}
};

int root[100000];

int find(int c) {
	if (c == root[c]) return c;
	return root[c] = find(root[c]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, res = 0;
	cin >> N;
	vector<Planet> p(N);
	vector<Adj> adj;
	for (int i = 0; i < N; i++) {
		root[i] = i;
		cin >> p[i].x >> p[i].y >> p[i].z;
		for (int j = 0; j < i; j++) {
			adj.push_back(Adj(i, j, p[i] - p[j]));
		}
	}
	sort(adj.begin(), adj.end());
	for (int i = 0; N > 1; i++) {
		int uroot = find(adj[i].u), vroot = find(adj[i].v);
		if (uroot != vroot) {
			root[vroot] = uroot;
			res += adj[i].w;
			N--;
		}
	}
	cout << res;
	return 0;
}