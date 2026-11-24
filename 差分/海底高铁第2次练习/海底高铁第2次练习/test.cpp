#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];//数组定义在全局默认初始化为0
int P[N];
int dif[N];
//int A[N], B[N], C[N];
long long A[N], B[N], C[N];


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> P[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	for (int i = 1; i < m; i++)
	{
		int l = min(P[i], P[i + 1]);
		int r = max(P[i], P[i + 1])-1 ;
		dif[l]++;
		dif[r + 1]--;
	}
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + dif[i];
	}
	long long ret = 0;
	for (int i = 1; i < n; i++)
	{
		ret += min(A[i] * a[i], B[i] * a[i] + C[i]);
		//这里原本我A,B,C数组都定义成int了int类型的，结果int*int结果还是int,这道题看数据范围结果可能为10^10,所以A,B,C数组和ret都要定义成long long
		//10^10是百亿，10^9是十亿，int是2.1*10^9
	
	}
	cout << ret;
	return 0;
}