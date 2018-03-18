#include <cstdio>
using namespace std;

int main(void) {
	int tc, x1, y1, r1, x2, y2, r2;
	int sum, sub, d;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		sum = (r1 + r2)*(r1 + r2);
		sub = (r1 - r2)*(r1 - r2);
		d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
		if (sub > d) {
			printf("0\n");
		}
		else if (sub == d) {
			if (d == 0)
				printf("-1\n");
			else
				printf("1\n");
		}
		else { // sub < d
			if (sum > d)
				printf("2\n");
			else if (sum == d)
				printf("1\n");
			else // sum < d
				printf("0\n");
		}
	}
	return 0;
}