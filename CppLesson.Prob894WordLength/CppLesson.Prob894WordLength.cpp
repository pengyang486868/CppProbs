#include "pch.h"

using namespace std;

// --------------------------------------------
// 省略头部 以下从using namespace std;之后开始
// --------------------------------------------

// --------------------------------------------
// 解法1：遍历判断 逐个输出
// 
// --------------------------------------------
void WordLength1(string input) {
	int num = 0;
	for (int i = 0; i < input.length(); i++) {
		// 是单词
		if (input[i] != 32) {
			num++;
		}

		// 由于空格而停止时
		if (input[i] == 32||i== input.length()-1) {
			if (num > 0) {
				cout << num;
				cout << ",";
			}
			num = 0;
		}

		// 由于句尾而停止时，注意不要再输出逗号了
		if (i == input.length() - 1) {
			if (num > 0) {
				cout << num;
				//cout << ",";！！不要再输出逗号了
			}
		}
	}
	
}

// --------------------------------------------
// 解法2：使用sstream
// 参考课件附带的【切分字符串】的方法 逐个>>word
// 在此补充完整
// --------------------------------------------
void WordLength2(string input) {

	//cout << 2;
}

// --------------------------------------------
// 主函数 
// 
// --------------------------------------------
int main()
{
	string input;
	getline(cin, input);

	WordLength1(input);
	//WordLength2(input);

	return 0;
}
