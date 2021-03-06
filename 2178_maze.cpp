#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int i, j, vx, vy, condition = 1;
	int N, M, maze[102][102] = { 0, };
	int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
	queue<pair<int, int>> Q;
	pair<int, int> v; // vertax
	
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
		for(j = 1; j<= M; j++)
		scanf("%1d", &maze[i][j]);

	Q.push(make_pair(1, 1));
	maze[1][1] = 2;
	while (condition && !Q.empty()) {
		v = Q.front();
		Q.pop();

		for (i = 0; i < 4; i++) {
			vx = v.first + dir[i][0];
			vy = v.second + dir[i][1];
			if (maze[vx][vy] > 0 && maze[vx][vy] < maze[v.first][v.second]) {
				maze[vx][vy] = maze[v.first][v.second] + 1;
				if (vx == N && vy == M) {
					condition = 0;
					break;
				}
				Q.push(make_pair(vx, vy));
			}
		}
	}
	printf("%d\n", maze[N][M] - 1);
    return 0;
}