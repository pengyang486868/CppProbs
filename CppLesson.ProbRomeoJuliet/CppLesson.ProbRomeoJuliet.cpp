#include "pch.h"
#define N 20
#define INF 10000
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
float ans = INF;
int startx, starty, endx, endy;
char f[N][N];

void dfs(int x, int y, int len) {
	if (x == endx && y == endy) {
		ans = ans > len ? len : ans;
		return;
	}

	f[x][y] = 'x';
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && (f[nx][ny] == 'o'|| f[nx][ny] == 'J'))
			dfs(nx, ny, len + 1);
	}
	f[x][y] = 'o';
}

int main() {
	freopen("input3.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> f[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i][j] == 'L') {
				startx = i;
				starty = j;
			}
			if (f[i][j] == 'J') {
				endx = i;
				endy = j;
			}
		}
	}

	dfs(startx, starty, 0);
	if (ans < INF) cout << ans/2.0 << endl;
	else cout << "forever" << endl;
	return 0;
}
