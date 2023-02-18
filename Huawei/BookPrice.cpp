/*
	每个用户初始金额300
 
	1、扣除规则
	1）图书价格大于等于 100元，累计借出去天数小于等于15天，每本每天租金5元，累计超过15天的，超过的天数每天每本租金3元
	2）图书价格大于等于 50元、小于100元，累计借出去天数小于等于15天，每本每天租金3元，累计超过15天的，超过的天数每天每本租金2元
	3）图书价格小于 50元，每本每天租金1元
 
	2、余额小于所借图书价格，不能借；可以继续借阅其他的书
 
	3、租金最大不超过所借图书的价格

	4、超期还书，每超过一天，另外扣1元

	输出余额

	例子：
	[[130,5,11],[60,16,16],[10,11,11]]

	输出：
	182

	解释：
	130,5,11   实际11天，超期6天，则租金为 11*5+6 = 61
	60,16,16   实际11天，有一天超过15天，则租金为 15*3 + 2 = 47
	10,11,11   实际11天，11*1 = 11，大于图书价格10元，则租金为10
	总共为 61+47+10 = 118，余额 182
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
参数：
	bookPrice: 图书价格
	balance:	余额
	realDay:	实际借书天数
	overdueDay:	超期天数


*/
int CalcUsedMoney(int bookPrice, int balance, int realDay, int overdueDays)
{
	int usedMoney = 0;
	if (bookPrice < 50)
	{
		usedMoney = realDay * 1 + overdueDays * 1;
	}
	else if (bookPrice >= 50 && bookPrice < 100)
	{
		if (realDay <= 15)
		{
			usedMoney = realDay * 3 + overdueDays * 1;
		}
		else
		{
			usedMoney = 45 + (realDay - 15) * 2 + overdueDays * 1;
		}
	}
	else if (bookPrice >= 100)
	{
		if (realDay <= 15)
		{
			usedMoney = realDay * 5 + overdueDays * 1;
		}
		else
		{
			usedMoney = 75 + (realDay - 15) * 3 + overdueDays * 1;
		}
	}

	if (usedMoney > bookPrice) usedMoney = bookPrice;

	return usedMoney;
}


int main(int argc, char* argv[])
{
	typedef struct {
		int bookPrice;
		int expectDay;
		int realDay;
	}BorrowBookInfo;

	vector<BorrowBookInfo> books;
	books.push_back({ 130,5,11 });
	books.push_back({ 60,16,16 });
	books.push_back({ 10,11,11 });

	int n = books.size();
	int usedMoney = 0;
	int balance = 300;
	int overdueDays = 0;
	if (n <= 0) return 300;
	for (int i = 0; i < n; i++)
	{
		overdueDays = 0;
		if (balance < books[i].bookPrice)
		{
			cout << "余额小于所借图书价格，不能借；可以继续借阅其他的书" << endl;
			break;
		}

		if (books[i].expectDay < books[i].realDay) overdueDays = books[i].realDay - books[i].expectDay;

		usedMoney = CalcUsedMoney(books[i].bookPrice, balance, books[i].realDay, overdueDays);
		balance -= usedMoney;
	}

	cout << balance << endl;

	system("pause");
	return 0;
}