/*
 * 题目：连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
 * 长度不是8整数倍的字符串请在后面补数字0，空字符串不处理
 * @author hexiaoli
 * 思路：
 *  1）常规（递归）：如果字符串长度大于8小于等于8两种情况
 *  小于等于8的时候，索引值index如果小于字符串长度，输出字符串中的字符，否则输出0；
 *  大于8的时候，索引值index在0-7时输出，换行，再递归输出字符串索引值8之后的
 *  2）直接判断字符串长度是不是8的倍数，不是补0，以8为长度，然后递归输出
*/


#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	while (1)
	{
		string s;
		cout << "please input a string: " << endl;
		cin >> s;

		s = s + "0000000";
		while (s.size() >= 8) 
		{
			/*
				substr有2种用法：
   				假设：string s = "0123456789";
				string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"
				string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"
			*/
			cout << s.substr(0, 8) << endl;
			s = s.substr(8);
		}
	}

	return 0;
}