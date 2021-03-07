#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int m, n;

	while (1) {		
		cout << "请输入处理器个数m和任务数n： " << endl;
		cin >> m >> n;
		int input;
		vector<int> time;
		cout << "请输入" << n << "个时间: "<< endl;
		for (int i = 0; i < n; i++) {
			cin >> input;
			time.push_back(input);
		}

		sort(time.begin(), time.end());

		int len = time.size();
		int index;
		if (len % m == 0)
		{
			index = m - 1;
		}
		else
		{
			index = len % m - 1;
		}
		int res = 0;
		for (int i = index; i < len; i = i + 3) {
			res += time[i];
		}

		cout << res << endl;
	}

	return 0;
}