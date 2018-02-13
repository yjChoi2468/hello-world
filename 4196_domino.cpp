//indegree가 0인 scc 개수 구하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <memory.h>
using namespace std;

#define MX 100000

int cnt, t, dfsn[MX], scc[MX];
vector<int> adj[MX]; // vector<vector<int>> adj;
stack<int> s;

int dfs(int u) {
	int res = dfsn[u] = ++t;
	s.push(u);
	for (int v : adj[u]) {
		if (!dfsn[v])
			res = min(res, dfs(v));
		else if (!scc[v])
			res = min(res, dfsn[v]);
	}
	if (res == dfsn[u]) {
		int tmp;
		cnt++;
		do {
			tmp = s.top(); s.pop();
			scc[tmp] = cnt;
		} while (tmp != u);
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int N, M, x, y;
		bool in[MX]; 
		// adj.resize(N);
		cin >> N >> M;
		cnt = t = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(scc, 0, sizeof(scc));
		memset(in, false, sizeof(in));
		for (int i = 0; i < MX; i++) // adj.clear();
			adj[i].clear();
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			adj[x - 1].push_back(y - 1);
		}
		for (int i = 0; i < N; i++)
			if (!dfsn[i])
				dfs(i);
		for (int i = 0; i < N; i++)
			for (int j : adj[i])
				if (scc[i] != scc[j] && !in[scc[j]]) {
					cnt--;
					in[scc[j]] = true;
				}
		cout << cnt << '\n';
	}
	return 0;
}