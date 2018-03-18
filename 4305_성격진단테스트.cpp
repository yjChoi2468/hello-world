#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool is_scc[26];
int t, dfsn[26];
stack<int> st;
vector<vector<int>> adj;
vector<vector<int>> scc;

int tarjan(int &u) {
	int res = dfsn[u] = ++t;
	st.push(u);
	for (int v : adj[u]) {
		if (!dfsn[v])
			res = min(res, tarjan(v));
		else if (!is_scc[v])
			res = min(res, dfsn[v]);
	}
	if (res == dfsn[u]) {
		int tmp;
		vector<int> tmpscc;
		do {
			tmp = st.top(); st.pop();
			tmpscc.push_back(tmp);
			is_scc[tmp] = true;
		} while (tmp != u);
		sort(tmpscc.begin(), tmpscc.end());
		scc.push_back(tmpscc);
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	char input[6];
	cin >> N;
	while (N != 0) {
		vector<int> out;
		t = 0;
		scc.clear();
		adj.clear();
		adj.resize(26);
		memset(dfsn, 0, sizeof(dfsn));
		memset(is_scc, false, sizeof(is_scc));
		/* input */
		for (int i = 0; i < N; i++) {
			for (int i = 0; i < 6; i++)
				cin >> input[i];
			out.push_back(input[5] - 'A');
			for (int i = 0; i < 5; i++)
				if (input[i] != input[5])
					adj[input[5] - 'A'].push_back((int)(input[i] - 'A'));
		}
		/* tarjan */
		for (int i : out)
			if (!dfsn[i])
				tarjan(i);
		sort(scc.begin(), scc.end());
		for (int i = 0; i < scc.size(); i++) {
			for (int ch : scc[i])
				cout << (char)(ch + 'A') << ' ';
			cout << '\n';
		}
		cout << '\n';
		cin >> N;
	}
	return 0;
}