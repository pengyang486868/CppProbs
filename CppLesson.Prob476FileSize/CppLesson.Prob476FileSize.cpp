// CppLesson.Prob476FileSize.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>

using namespace std;

double SizeOf(string str) {
	double d;
	string noend = str.substr(0, str.length() - 1);
	stringstream sstr(noend);
	sstr >> d;

	if (str[str.length() - 1] == 'K')
		return d / 1024.0;
	else if (str[str.length() - 1] == 'M')
		return d;
	else {
		stringstream sstr(str);
		sstr >> d;
		return d / 1024.0 / 1024.0;
	}
}

// main
int main()
{
	int fileCount, queryCount;
	double files[100000];

	freopen("input.txt", "r", stdin);

	string curFlieStr;
	cin >> fileCount >> queryCount;
	for (int i = 0; i < fileCount; i++) {
		cin >> curFlieStr;
		files[i] = SizeOf(curFlieStr);
	}

	int currentStart, currentEnd;
	double currentSize;
	freopen("output.txt", "w", stdout);
	cout << setiosflags(ios::fixed) << setprecision(1);
	for (int i = 0; i < queryCount; i++) {
		cin >> currentStart >> currentEnd;
		currentSize = 0.0;
		for (int j = currentStart - 1; j < currentEnd; j++) {
			currentSize += files[j];
		}
		cout << currentSize << "M" << endl;
	}

	return 0;
}

