#define _CRT_SECURE_NO_WARNINGS
//https ://www.luogu.com.cn/problem/P1003
#include<iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N], b[N], g[N], k[N];
int main()
{
	int n;
	int x, y;
	int find = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	}
	cin >> x >> y;
	for (int i = n; i >= 1; i--)
	{
		if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i])
		{	
			cout << i;
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		cout << -1;
	}
	return 0;
}