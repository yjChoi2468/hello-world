#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define N 10001

int V, E, t, visit[N];
bool is_scc[10000];
vector<int> edge[N];
stack<int> s;
vector<vector<int>> scc;

int tarjan(int u) {
	int res = visit[u] = ++t;
	s.push(u);
	for (int v : edge[u]) {
		if (!visit[v])
			res = min(res, tarjan(v));
		else if (!is_scc[v])
			res = min(res, visit[v]);
	}

	if (res == visit[u]) {
		vector<int> tmpscc;
		int tmp;
		do{
			tmp = s.top(); s.pop();
			is_scc[tmp] = true;
			tmpscc.push_back(tmp);
		} while (tmp != u);
		sort(tmpscc.begin(), tmpscc.end());
		scc.push_back(tmpscc);
	}
	return res;
}

void print_scc() {
	sort(scc.begin(), scc.end());
	cout << scc.size() << '\n';
	for (auto tmpscc : scc) {
		for (int i : tmpscc)
			cout << i << ' ';
		cout << -1 << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (int i = 1; i <= V; i++)
		if (!visit[i])
			tarjan(i);
	print_scc();
	return 0;
}
