#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
	int vNum, eNum, root;
	int vnear;
	vector<pair<int, int>> edge[20010];
	set<pair<int, int>> s;
	pair<int, int> node;
	int length[20010];

	scanf("%d %d %d", &vNum, &eNum, &root);
	for (int v1, v2, w, i = 0; i < eNum; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		edge[v1].push_back(make_pair(w, v2));
	}

	for (int i = 1; i <= vNum; i++) length[i] = 1e9;
	length[root] = 0;

	s.insert(make_pair(0, root));
	while (!s.empty()) {
		node = *s.begin();
		s.erase(s.begin());
		int from = node.second;

		for (int i = 0; i < edge[from].size(); i++)
		{
			int to = edge[from][i].second;
			if (length[to] > length[from] + edge[from][i].first)
			{
				if (length[to] != 1e9)
					s.erase(s.find(make_pair(length[to], to)));
				length[to] = length[from] + edge[from][i].first;
				s.insert(make_pair(length[to], to));
			}
		}
	}
	for (int i = 1; i <= vNum; i++) {
		if (length[i] == 1e9) printf("INF\n");
		else printf("%d\n", length[i]);
	}
	return 0;
}