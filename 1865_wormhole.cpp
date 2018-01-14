/*
G[505]: Graph
G[v1].first: weight of edge from v1 to v2
G[v2].second: v2

when using set<> in Graph 132ms time
when using vector<> in Graph 28ms time
*/

#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

struct p {
	int x, w, y;
};

int main(void)
{
	int T, V, E, W;

	scanf("%d", &T);
	while (T--) {
		bool cycle = false;
		int dist[505];
		int s, d, w;
		vector<p> G;

		scanf("%d %d %d", &V, &E, &W);
		dist[1] = 0;
		for (int i = 2; i <= V; i++) dist[i] = INT_MAX;
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &s, &d, &w);
			G.push_back({ s, w, d }); 
			G.push_back({ d, w, s });
		}
		for (int i = 0; i < W; i++) {
			scanf("%d %d %d", &s, &d, &w);
			G.push_back({ s, -w, d });
		}

		for (int i = 1; i <= V; i++)
			for (auto edge : G) {
				int v1 = edge.x, v2 = edge.y, w = edge.w;
				if (dist[v1] != INT_MAX && dist[v1] + w < dist[v2]) {
					dist[v2] = dist[v1] + w;
					if (i == V) cycle = true;
				}
			}

		cycle ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}