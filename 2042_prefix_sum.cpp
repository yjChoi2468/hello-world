#include <iostream>
using namespace std;

#define ll long long

int arr[1000001];
ll tree[2097155]; // 2

/*
idx: index of tree
i:index of arr
s:start of arr sum
e:end of arr sum
*/
ll init(int idx, int s, int e) {
	if (s == e)
		return tree[idx] = arr[s];
	int mid = (s + e) / 2;
	return tree[idx] = init(idx * 2, s, mid) + init(idx * 2 + 1, mid + 1, e);
}

void update(int idx, int i, int s, int e, ll diff) {
	if (s > i || i > e)
		return;
	tree[idx] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(idx * 2, i, s, mid, diff);
		update(idx * 2 + 1, i, mid + 1, e, diff);
	}
	return;
}

ll sum(int idx, int sumS, int sumE, int s, int e) {
	if (e < sumS || sumE < s)
		return 0;
	if (sumS <= s && e <= sumE)
		return tree[idx];
	int mid = (s + e) / 2;
	return sum(idx * 2, sumS, sumE, s, mid) + sum(idx * 2 + 1, sumS, sumE, mid + 1, e);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, 1, N, c - arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(1, b, c, 1, N) << '\n';
		}
	}
	return 0;
}