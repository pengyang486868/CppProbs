#include "pch.h"

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
	for (j = 1; j <= m; j++) cout << ans[j] << endl;
}


int main() {
	//OldMethod();
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> s[i];
	sort(s, s + n);

	freopen("output.txt", "w", stdout);
	for (j = 1; j <= m; j++) {
		cin >> d;
		cout << upper_bound(s, s + n, d) - s << endl;
	}

	return 0;
}