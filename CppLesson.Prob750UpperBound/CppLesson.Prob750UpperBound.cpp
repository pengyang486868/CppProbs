﻿#include "pch.h"

#define N 1000000
using namespace std;

long long a, n, m, i, j, s[N], d, ans[N];

void OldMethod() {
	freopen("input.txt", "r", stdin);
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

	freopen("output.txt", "w", stdout);
	for (j = 1; j <= m; j++) {
		cout << ans[j];
		if (j < m)
			cout << endl;
	}
}


int main() {
	//freopen("fuli.in", "r", stdin);
	//freopen("fuli.out", "w", stdout);
	//OldMethod();
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);

	freopen("output.txt", "w", stdout);
	for (j = 1; j <= m; j++) {
		cin >> d;
		cout << upper_bound(s, s + n, d) - s;
		/*if (s[n - 1] <= d)cout << n;
		else {
			for (int k = 0;k < n - 1;k++) {
				if (s[k] <= d && s[k + 1] > d) {
					cout << k+1;
					break;
				}
			}
		}*/
		if (j < m)
			cout << endl;
	}

	return 0;
}