#include "pch.h"
#include<iostream>
#define N 20
#define INF 10000
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, ans = INF;
char f[N][N];
void dfs(int x, int y, int len) {
	if (x == n && y == m) { ans = min(ans, len); return; }
	f[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && f[nx][ny] == 'o' && !f[nx][ny])
			dfs(nx, ny, len + 1);
	}
	f[x][y] = 0;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> f[i][j];
	dfs(0, 0, 0);
	if (ans < INF) cout << ans << endl;
	else cout << "forever" << endl;
	return 0;
}
