#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

bool v[1000]; // visited[eating shark]
int m[1000]; // matched[eated shark]
int info[1000][3];
vector<vector<int>> adj;

bool dfs(int &src) {
	if (v[src]) return false;
	v[src] = true;
	for (int dest : adj[src])
		if (m[dest] == -1)
			return m[dest] = src, true;
	for (int dest : adj[src])
		if (dfs(m[dest]))
			return m[dest] = src, true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, eated = 0;
	cin >> N;
	adj.resize(N);
	for (int i = 0; i < N; i++)
		cin >> info[i][0] >> info[i][1] >> info[i][2];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (info[i][0] == info[j][0] && info[i][1] == info[j][1] && info[i][2] == info[j][2]) {
				if (i < j)
					adj[i].push_back(j);
			}
			else if (i != j && info[i][0] >= info[j][0] && info[i][1] >= info[j][1] && info[i][2] >= info[j][2])
				adj[i].push_back(j);
		}
	memset(m, -1, sizeof(m));
	for (int i = 0; i < N; i++) {
		memset(v, false, sizeof(v));
		if (dfs(i)) eated++;
		memset(v, false, sizeof(v));
		if (dfs(i)) eated++;
	}
	cout << N - eated;
	return 0;
}