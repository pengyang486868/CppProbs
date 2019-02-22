#include "pch.h"

using namespace std;

// --------------------------------------------
// 省略头部 以下从using namespace std;之后开始
// --------------------------------------------

// 原有的 应该是2的n次方
int mi(int n)
{
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans *= 2;
	return ans;
}

// 将一个数origin按base进制写成字符串
// 比如origin=6 base=2时候 返回110
string Transform(int origin, int base) {
	string temp = "";

	while (origin > 0) {
		temp += to_string(origin % base);
		origin = origin / base;
	}

	string result = "";
	for (int i = temp.length() - 1; i >= 0; i--)
		result += temp[i];

	return result;
}

// 将一个数origin按base进制写成字符串 且长度必须大于等于minLength 否则补0
// 比如origin=6 base=2 minLength=5时候 返回00110
string TransformFixed(int origin, int base, int minLength) {
	string temp = "";

	while (origin > 0) {
		temp += to_string(origin % base);
		origin = origin / base;
		//len++;
	}

	string result = "";
	if (minLength > temp.length()) {
		for (int i = 0; i < minLength - temp.length(); i++)
			result += "0";
	}
	for (int i = temp.length() - 1; i >= 0; i--)
		result += temp[i];

	return result;
}

// --------------------------------------------
// 解法1：原写法
// 效率较高 可以解决很大的k 缺点是代码很难懂 代码的可读性很重要
// --------------------------------------------
string Solution1(int k) {
	int t = log(k + 1) / log(2);
	string s = "";
	k -= mi(t) - 2;
	while (t)
	{
		if (k > (mi(t - 1) + 1))
		{
			k -= mi(t - 1);
			s += "8";
		}
		else if (k == (mi(t - 1) + 1))
		{
			k = 0; s += "8";
			for (int i = 0; i < t - 1; i++) s += "5";
			break;
		}
		else s += "5"; t--;
	}
	return s;
}

// --------------------------------------------
// 解法2：从头开始搜索
// 由于答案随k的增长很快 所以k=60以上就很慢了
// --------------------------------------------
string Solution2(int k) {
	int current = 1;
	int num = 0;

	while (true) {
		bool pass = true;
		string str = Transform(current, 10);
		//string compare = Transform(58, 10);
		for (int i = 0; i < str.length(); i++) {
			//if (!(str[i] == compare[0] || str[i] == compare[1])) {
			if (!(str[i] == '5' || str[i] == '8')) {
				pass = false;
				break;
			}
		}

		if (pass)
			num++;
		if (num == k)break;

		current++;
	}

	return Transform(current, 10);
}

// --------------------------------------------
// 解法3：先确定答案的字符串长度 再利用二进制的性质
// 速度与解法1差不多 也可以对很大的k
// --------------------------------------------
string Solution3(int k) {
	int len = 1;
	while (k > mi(len)) {
		k -= mi(len);
		len++;
	}

	//注意：第k个数的值是k-1
	string remain = TransformFixed(k - 1, 2, len);
	string result = "";

	//置换数字
	for (int i = 0; i < remain.length(); i++) {
		if (remain[i] == '0')
			result += "5";
		if (remain[i] == '1')
			result += "8";
	}

	return result;
}

// --------------------------------------------
// 主函数 附带打开文件和写文件
// 先放进去输入文件xysz.in 记事本编辑后修改扩展名
// --------------------------------------------
int main()
{
	int k;

	/*cin >> k;
	cout << Solution1(k) << endl;
	cout << Solution3(k) << endl;*/

	ifstream openFile("xysz.in");

	if (openFile.fail()){
		cout << "打开文件错误!" << endl;
		exit(0);
	}

	openFile >> k;
	openFile.close();//文件流使用后都应关闭

	ofstream outFile("xysz.out");
	outFile << Solution1(k);
	//Solution2(k) Solution3(k)

	outFile.close();//文件流使用后都应关闭

	return 0;
}
