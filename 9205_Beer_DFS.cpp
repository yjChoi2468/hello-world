// DFS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int V[105][2], n;
bool visit[105], res;
vector<int> D[105];

void bfs(int s) {
	if (s == n) {
		res = 1;
		return;
	}
	visit[s] = 1;
	for (int i : D[s])
		if (!visit[i])
			bfs(i);
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		n = n + 1;
		res = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i <= n; i++) {
			D[i].clear();
			cin >> V[i][0] >> V[i][1];
			for (int j = 0; j < i; j++) {
				int dist = abs(V[i][0] - V[j][0]) + abs(V[i][1] - V[j][1]);
				if (dist <= 1000) {
					D[i].push_back(j);
					D[j].push_back(i);
				}
			}
		}
		bfs(0);
		printf("%s\n", (res ? "happy" : "sad"));
	}
	return 0;
}