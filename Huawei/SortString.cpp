/*
	题目描述：
	输入一个字符串，长度小于等于200，然后将输出按字符顺序升序排序后的字符串。

	输入：
	测试数据有多组，输入字符串。

	输出：
	对于每组输入,输出处理后的结果。

	样例输入：
	bacd
	样例输出：
	abcd

	分析：
	首先输入多个字符串，冒泡排序之后输出，
*/


#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	while (1)
	{
		string s;
		cout << "input a string : " << endl;
		cin >> s;
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (s[j] > s[j + 1])
				{
					char tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
				}
			}
		}
		cout << s << endl;
	}

	return 0;
}