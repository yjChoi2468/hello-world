/*
1
3 2 4
1 2 1 2
1 2 2 1
1 3 1 4
2 3 1 1
->3
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
	int dest, cost, time;
	Edge(int d, int c, int t) { dest = d; cost = c; time = t; }
	//bool operator<(const Edge& e) const {return time > e.time;}
};

struct cmp {
	bool operator () (Edge e1, Edge e2) {
		return e1.time > e2.time;
	}
};

int dist[101][10001] = { 0, };
vector<Edge> edge[101];

int main(void)
{
	int T, N, M, K;
	int v1, v2, c, t;
	scanf("%d", &T);
	while (T--) {
		priority_queue<Edge, vector<Edge>, cmp> que; // dest, cost, time
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= N; i++) edge[i].clear();
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &v1, &v2, &c, &t);
			edge[v1].push_back(Edge(v2, c, t));
		}
		fill(&dist[0][0], &dist[N][M + 1], INT_MAX);
		que.push(Edge(1, 0, 0));
		dist[1][0] = 0;
		while (!que.empty()) {
			Edge now = que.top(); que.pop();
			v1 = now.dest;
			if (dist[v1][now.cost] < now.time) continue;
			dist[v1][now.cost] = now.time;
			if (v1 == N) {
				dist[N][0] = now.time;
				break;
			}
			for (auto it = edge[v1].begin(); it != edge[v1].end(); it++) { // for(Edge e: edge[v1])
				v2 = it->dest; c = it->cost; t = it->time;
				if (now.cost + c <= M && dist[v1][now.cost] != INT_MAX && dist[v1][now.cost] + t < dist[v2][now.cost + c]) {
					dist[v2][now.cost + c] = dist[v1][now.cost] + t;
					que.push(Edge(v2, now.cost + c, dist[v2][now.cost + c]));
				}
			}
		}
		if (dist[N][0] == INT_MAX) printf("Poor KCM\n");
		else printf("%d\n", dist[N][0]);
	}
	return 0;
}
