#include <cstdio>
#include <queue>
using namespace std;

int N, x[1000001] = { 0, };
int main(void) {
	queue<int> v;
	scanf("%d", &N);
	v.push(N);
	while (1) {
		int n = v.front(); v.pop();
		if (n == 1) break;
		if (n % 3 == 0 && x[n / 3] == 0)
		{
			x[n / 3] = x[n] + 1;
			v.push(n / 3);
		}
		if (n % 2 == 0 && x[n / 2] == 0)
		{
			x[n / 2] = x[n] + 1;
			v.push(n / 2);
		}
		if (n - 1 > 0 && x[n - 1] == 0)
		{
			x[n - 1] = x[n] + 1;
			v.push(n - 1);
		}
	}
	printf("%d", x[1]);
	return 0;
}