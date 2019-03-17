#include "pch.h"
#include<iostream>

using namespace std;

struct student {
	int id, chinese, math, english, total;
};

bool compare(student x, student y)
{
	if (x.total == y.total&&x.chinese == y.chinese)
		return x.id > y.id;
	if (x.total == y.total)
		return x.chinese > y.chinese;
	return x.total > y.total;
}

// main
int main()
{
	int stuCount;
	student stu[300];

	freopen("input.txt", "r", stdin);
	int curChi, curMath, curEng;
	cin >> stuCount;
	for (int i = 0; i < stuCount; i++) {
		cin >> curChi >> curMath >> curEng;
		stu[i].id = i + 1;
		stu[i].chinese = curChi;
		stu[i].math = curMath;
		stu[i].english = curEng;
		stu[i].total = curChi + curMath + curEng;
	}

	sort(stu, stu + stuCount, compare);


	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 5; i++) {
		if (i == 4)
			cout << stu[i].id << " " << stu[i].total;
		else
			cout << stu[i].id << " " << stu[i].total << endl;
	}

	return 0;
}

