#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<vector<int>> adj; // adj[employee] include works
int matched[1001]; // matched[work] = employee
bool visited[1001]; // visited[employee]

bool dfs(int &u) {
	if (visited[u]) return false;
	visited[u] = true;

	// 84ms
	for (int v : adj[u])
		if (!matched[v])
			return matched[v] = u, true;
	for (int v : adj[u])
		if (dfs(matched[v]))
			return matched[v] = u, true;

	/* 416ms
	for (int v : adj[u])
	if (!matched[v] || dfs(matched[v]))
	return matched[v] = u, true;
	*/
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, res = 0;
	cin >> N >> M;
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		int cnt, idx;
		cin >> cnt;
		while (cnt--) {
			cin >> idx;
			adj[i].push_back(idx);
		}
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i))
			res++;
	}

	cout << res;
	return 0;
}