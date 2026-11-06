#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;
//洛谷 多项式输出
//https://www.luogu.com.cn/problem/P1067

int main()
{
	int n;
	cin >> n;
	for (int i = n; i >= 0; i--)
	{
		int m;
		cin >> m;
		if (m == 0)
		{
			continue;
		}
		if (i == n)
		{
			if (m < 0)
			{
				cout << '-';
			}
		}
		else
		{
			if (m > 0)
			{
				cout << '+';
			}
			else
			{
				cout << '-';
			}
		}
		int k = abs(m);
		if (k == 1)
		{
			if (i == 0)
			{
				cout << k;
			}

		}
		else
		{
			cout << k;
		}
		if (i == 1)
		{
			cout << 'x';
		}
		else if (i == 0)
		{

		}
		else 
		{
			cout << "x^" << i;
		}
	}
	return 0;
}