#include "pch.h"
#include <iostream>

#define N 1000000
using namespace std;
long long a, n, m, i, j, s[N], d, ans[N];
int main() {
	for (a = 0; a < N; a++)
		ans[a] = 0;
	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> s[i];
	for (j = 1; j <= m; j++) {
		cin >> d;
		for (i = 1; i <= n; i++) {
			if (s[i] <= d)
				ans[j]++;
		}
	}

	for (j = 1; j <= m; j++) cout << ans[j] << endl;
	return 0;
}