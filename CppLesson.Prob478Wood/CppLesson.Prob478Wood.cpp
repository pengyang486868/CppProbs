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
	while (startrow + hisrow < row) {
		while (startcol + hiscol < col) {
			currentwood = 0;
			for (int i = startrow; i < startrow + hisrow; i++) {
				for (int j = startcol; j < startcol + hiscol; j++)
					currentwood += map[i][j];
			}

			if (currentwood > maxwood)
				maxwood = currentwood;

			startcol++;
		}
		startrow++;
	}

	cout << maxwood;

	return 0;
}

