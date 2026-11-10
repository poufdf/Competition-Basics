#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

//注意考虑数据是否会溢出，如会就用long long存数据
//在一个数组上进行加减操作，考虑用差分数组
const int N = 1e5 + 10;
long long arr[N] = { 0 };
long long dif[N] = { 0 };
long long A[N] = { 0 };
long long B[N] = { 0 };
long long C[N] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < m; i++)
	{
		int l = arr[i];
		int r = arr[i + 1];
		if (l < r)
		{
			dif[l]++;
			dif[r]--;
		}
		else
		{
			dif[r]++;
			dif[l]--;
		}

	}
	for (int i = 1; i < n; i++)
	{
		dif[i] = dif[i - 1] + dif[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	long long price = 0;
	for (int i = 1; i < n; i++)
	{
		price += min(A[i] * dif[i], C[i] + B[i] * dif[i]);
	}
	cout << price;

	return 0;
}