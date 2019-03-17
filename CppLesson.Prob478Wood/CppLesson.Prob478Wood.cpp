#include "pch.h"
#include<iostream>

using namespace std;

int main()
{
	int row, col, hisrow, hiscol;
	int map[500][500];

	freopen("input.txt", "r", stdin);
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> map[i][j];
	}
	cin >> hisrow >> hiscol;

	freopen("output.txt", "w", stdout);

	int startrow = 0, startcol = 0;
	int currentwood, maxwood = 0;
	while (startrow + hisrow <= row) {
		int prevwood = 0;
		for (int i = startrow; i < startrow + hisrow; i++) {
			for (int j = startcol; j < startcol + hiscol; j++)
				prevwood += map[i][j];
		}
		startcol++;

		while (startcol + hiscol <= col) {
			currentwood = prevwood;
			for (int i = startrow; i < startrow + hisrow; i++) {
				currentwood -= map[i][startcol - 1];
				currentwood += map[i][startcol + hiscol - 1];
			}

			if (currentwood > maxwood)
				maxwood = currentwood;

			startcol++;
			prevwood = currentwood;
		}
		startcol = 0;
		startrow++;
	}

	cout << maxwood;

	return 0;
}

