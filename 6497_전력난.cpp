#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int a, int b, int c) :u(a), v(b), w(c) {}
	bool operator < (const Edge &b) const {
		return this->w < b.w;
	}
};

int scc[200000];

int find(int c) {
	if (scc[c] == c) return c;
	return scc[c] = find(scc[c]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n, cost;
	cin >> m >> n;
	while (m != 0 && n != 0) {
		vector<Edge> edge(n);
		cost = 0;
		for (int i = 0; i < m; i++)
			scc[i] = i;
		for (int i = 0; i < n; i++) {
			cin >> edge[i].u >> edge[i].v >> edge[i].w;
			cost += edge[i].w;
		}
		sort(edge.begin(), edge.end());
		for (int i = 0; m > 1; i++) {
			int uroot = find(edge[i].u), vroot = find(edge[i].v);
			if (uroot != vroot) {
				scc[vroot] = uroot;
				cost -= edge[i].w;
				m--;
			}
		}
		cout << cost << '\n';
		cin >> m >> n;
	}
	return 0;
}