#pragma warning(disable:4996)

#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;


int l, bsy, ans, a[110], f[10010], far[10010], flag[10100];
int s, t, m;


int main() {
	scanf("%d", &l);
	scanf("%d%d%d", &s, &t, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % s == 0)
			bsy++;
	}
	if (s == t)//特判
	{
		printf("%d", bsy);
		return 0;
	}
	sort(a + 1, a + m + 1);
	far[m + 1] = min(l - a[m], 100);//最后一个点到终点的距离
	l = 0;
	for (int i = 1; i <= m; i++)//路径压缩
	{//存储缩短后的距离并标记石头位置
		far[i] = min(a[i] - a[i - 1], 90);
		l += far[i];
		flag[l] = 1;
	}
	l += far[m + 1];
	for (int i = 1; i <= l + 9; i++)
	{
		f[i] = 2147483640;
		for (int j = s; j <= t; j++)
		{
			if (i >= j)
				f[i] = min(f[i], f[i - j] + flag[i]);
		}
	}
	ans = 2147483640;
	for (int i = l; i <= l + 9; i++)//因为青蛙可以跳出边界且t<=10因此再终点后l-l+9中取最小值
		ans = min(ans, f[i]);
	printf("%d", ans);
}
