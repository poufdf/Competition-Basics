#define _CRT_SECURE_NO_WARNINGS
//…ﬂ–Œ∑Ω’Û
//https://www.luogu.com.cn/problem/P5731
#include<iostream>

using namespace std;
const int N = 10;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int arr[N][N] = { 0 };


int main()
{
	int n = 0;
	cin >> n;
	int temp = 1;
	int x = 1;
	int y = 1;
	int pos = 0;
	while (temp <= n * n)
	{
		arr[x][y] = temp;
		int a = x + dx[pos];
		int b = y + dy[pos];
		if (a > n || b > n || b < 1 || arr[a][b] != 0)
		{
			pos = (pos + 1) % 4;
			a = x + dx[pos];
			b = y + dy[pos];
		}
		x = a;
		y = b;
		temp++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}
	return 0;
}			
			