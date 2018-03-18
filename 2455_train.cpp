#include <iostream>

int main(void) {

	int cnt = 0, num, mx = 0;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &num);
		if (i & 1)
			mx = mx > (cnt += num) ? mx : cnt;
		else
			cnt -= num;
	}
	printf("%d", mx);
	return 0;
}