#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct FirstOrder
{
	int microSecond;
	int count;
};

string getFirstPartTime(string timeStr)
{
	size_t n = timeStr.find_first_of('.');
	string firstPart(timeStr.c_str(), timeStr.c_str() + n);
	return firstPart;
}

int getSecondPartTime(string timeStr)
{
	size_t n = timeStr.find_first_of('.');
	n++;
	return atoi(timeStr.c_str() + n);
}

int main(int argc, char** argv)
{
	string line;
	map<string, FirstOrder> staticsMap;
	// 记录 每秒钟第一个下单的人数
	while (getline(cin, line))
	{
		string s = getFirstPartTime(line);
		int ms = getSecondPartTime(line);
		map<string, FirstOrder>::iterator it = staticsMap.find(s);
		if (it != staticsMap.end()) // 在 map 中已经存在，需要更新
		{

			if (ms < it->second.microSecond)
			{
				it->second.microSecond = ms;
				it->second.count = 1;
			}
			else if (ms == it->second.microSecond)
			{
				it->second.count++;
			}
		}
		else // 不存在，需要插入
		{
			FirstOrder order;
			order.microSecond = ms;
			order.count = 1;
			staticsMap.insert(make_pair(s, order));
		}
	}

	// 统计所有第一个下单的人数
	size_t freeOrderNum = 0;
	map<string, FirstOrder>::iterator it = staticsMap.begin();
	while (it != staticsMap.end())
	{
		freeOrderNum += it->second.count;
		it++;
	}
	cout << freeOrderNum << endl;
}