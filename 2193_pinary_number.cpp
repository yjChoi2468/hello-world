#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	long long ans = 1, a = 1, b = 1;
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		ans = a + b; 
		a = b; b = ans;
	}
	cout << ans;
	return 0;
}