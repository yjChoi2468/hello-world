#include <cstdio>
#include <climits>
#include <vector>
#include <set>
using namespace std;

void dijkstra(int, int);
int N, dist[3][805];
vector<pair<int, int>> edge[805];

int main(void)
{
	int E, V1, V2;
	int a, b, c;
	int min1 = 0, min2 = 0;
	bool one = true, two = true;

	scanf("%d %d", &N, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(c, b));
		edge[b].push_back(make_pair(c, a));
	}
	scanf("%d %d", &V1, &V2);

	dijkstra(1, 0); dijkstra(V1, 1); dijkstra(V2, 2);
	int arr[6] = { V1, V2, N, V2, N, V1 }, min[2] = { 0, };
	for (int i = 0; i < 6; i++)
		dist[i % 3][arr[i]] != INT_MAX ? min[i / 3] += dist[i % 3][arr[i]] : min[i / 3] = INT_MIN;

	if (min[0] * min[1] < 0) printf("%d", min[0] > 0 ? min[0] : min[1]);
	else printf("%d", min[0] > 0 ? (min[0] < min[1] ? min[0] : min[1]) : -1);
	return 0;
}

void dijkstra(int src, int it)
{
	set<pair<int, int>> s;

	for (int i = 1; i <= N; i++) dist[it][i] = INT_MAX;
	dist[it][src] = 0;

	s.insert(make_pair(0, src));
	while (!s.empty()) {
		auto tmp = *s.begin();
		s.erase(tmp);
		int from = tmp.second;
		for (int i = 0; i < edge[from].size(); i++) {
			int to = edge[from][i].second;
			int weight = edge[from][i].first;
			if (dist[it][to] > dist[it][from] + weight) {
				if (dist[it][to] != INT_MAX) s.erase(s.find(make_pair(dist[it][to], to)));
				dist[it][to] = dist[it][from] + weight;
				s.insert(make_pair(dist[it][to], to));
			}
		}
	}
	return;
}