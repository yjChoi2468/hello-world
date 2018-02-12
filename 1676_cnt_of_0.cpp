#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 5, tmp = i; i <= n; tmp = i += 5) {
		while (tmp % 5 == 0) {
			cnt++;
			tmp /= 5;
		}
	}
	cout << cnt;
	return 0;
}