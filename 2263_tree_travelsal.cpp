/*
3
3 2 1
3 2 1
->1 2 3

6
5 4 3 6 2 1
5 4 6 3 2 1
->1 2 3 4 5 6

9
5 4 3 7 6 8 9 2 1
5 4 7 9 8 6 3 2 1
->1 2 3 4 5 9 6 7 8

3
1 2 3
3 2 1
-> 1 2 3

9
3 4 9 5 2 6 1 8 7
9 5 4 3 6 2 8 7 1
->1 2 3 4 5 6 7 8 9
*/
#include <cstdio>
using namespace std;

int in[100000], post[100000];
int in_idx[100001];
void dnc(int inL, int inR, int postL, int postR) {
	if (postL > postR) return;
	int root = post[postR], root_idx = in_idx[root];
	printf("%d ", root);
	dnc(inL, root_idx - 1, postL, postL + (root_idx - inL) - 1); // L
	dnc(root_idx + 1, inR, postR - (inR - root_idx), postR - 1); // R
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		in_idx[in[i]] = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	dnc(0, n - 1, 0, n - 1);
	return 0;
}

/*
#include <cstdio>
using namespace std;

int in[100000], post[100000], tree[100001][2];
bool visit[100001];
void dfs(int r) {
	if (r == 0) return;
	printf("%d ", r);
	dfs(tree[r][0]);
	dfs(tree[r][1]);
	return;
}

int main(void) {
	int n, child = 0, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &in[i]);
	for (i = 0; i < n; i++) scanf("%d", &post[i]);
	visit[post[n - 1]] = true;
	for (i = j = n - 1; j > 0;) { // right child
		if (in[i] == post[j]) {
			i--; j--;
		}
		else if (tree[in[i]][1]) {
			i--;
		}
		else {
			tree[post[j--]][1] = post[j - 1];
			visit[post[j]] = true;
		}
	}
	for (i = 0; i < n; i++) { // left child
		if (!visit[in[i]]) {
			int tmp = in[i], k = i;
			while (tree[tmp][1]) tmp = tree[tmp][1];
			while (tmp != in[k++]) ;
			tree[in[k]][0] = in[i];
		}
	}
	dfs(post[n - 1]);
	return 0;
}
*/