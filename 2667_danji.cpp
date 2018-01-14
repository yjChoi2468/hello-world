#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[30][30] = { "", };
void dfs(int x, int y, int *num);

int main(void)
{
	int N, cnt = 0, num = 0;
	vector<int> D;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> &map[i][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1') {
				dfs(i, j, &num);
				D.push_back(num);
				cnt++;
			}
			num = 0;
		}
	}
	sort(D.begin(), D.end());
	
	cout << cnt;
	for (vector<int>::iterator it = D.begin(); it != D.end(); ++it)
		std::cout << endl << *it;
	return 0;
}

void dfs(int x, int y, int *num)
{
	int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	
	map[x][y] = '0';
	(*num)++;
	for (int i = 0; i < 4; i++)
		if (map[x + dir[i][0]][y + dir[i][1]] == '1')
			dfs(x + dir[i][0], y + dir[i][1], num);
	return;
}
/*
3
101
000
101

4 1 1 1 1

7
0110100
0110101
1111101
0000111
0100000
0111110
0111000

2 9 16
*/