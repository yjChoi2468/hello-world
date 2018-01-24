#include <cstdio>
#include <algorithm>

int main(void) {
	int n, in = -1001, ex = -1001, cur;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cur);
		ex = std::max(ex, in);
		in = std::max(cur, in + cur);
	}
	printf("%d", ex > in ? ex : in);
	return 0;
}