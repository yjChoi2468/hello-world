/*
G[505]: Graph
G[v1].first: weight of edge from v1 to v2
G[v2].second: v2
*/

#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

typedef struct edge {
	int src, dest, weight;
	edge(int s, int d, int w) {
		src = s; dest = d; weight = w;
	}
}edge;

int main(void)
{
	int V, E, s, d, w;
	bool cycle = false;
	int dist[505];
	vector<edge> graph;
	scanf("%d %d", &V, &E);
	dist[1] = 0;
	for (int i = 2; i <= V; i++) dist[i] = INT_MAX;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &s, &d, &w);
		graph.push_back(edge(s, d, w));
	}

	for (int i = 1; i <= V; i++)
		for (int j = 0; j < graph.size(); j++) {
			int v1 = graph[j].src, v2 = graph[j].dest, w = graph[j].weight;
			if (dist[v1] != INT_MAX && dist[v1] + w < dist[v2]) {
				dist[v2] = dist[v1] + w;
				if (i == V) cycle = true;
			}
		}

	if (cycle) printf("-1\n");
	else
		for(int i = 2; i <= V; i++)
			printf("%d\n", dist[i] != INT_MAX ? dist[i] : -1);
	return 0;
}