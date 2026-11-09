#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

const int N = 2e5 + 10;
int sum[N] = { 0 };
int main()
{
	int n,x;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	int tempmax = -1e5;
	int prevmin = 0;
	for (int i = 1; i <= n; i++)
	{
		tempmax = max(tempmax,sum[i]-prevmin);
		prevmin = min(prevmin, sum[i]);

	}
	cout << tempmax;
	return 0;
}
























//#include<iostream>
//
//using namespace std;
//
//const int N = 2e5 + 10;
//int arr[N] = { 0 };
//int sum[N] = { 0 };
//
////时间复杂度为O(n^2)，必然超时
//int main()
//{
//	int n;
//	int temp = 0;
//	int max = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		sum[i] = sum[i - 1] + arr[i];
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = i; j <= n; j++)
//		{
//			temp = sum[j] - sum[i - 1];
//			if (temp > max)
//			{
//				max = temp;
//			}
//		}
//
//	}
//	cout << max;
//	return 0;
//}
