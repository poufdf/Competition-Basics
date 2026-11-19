#define _CRT_SECURE_NO_WARNINGS
//https://www.luogu.com.cn/problem/P2280

#include<iostream>

using namespace std;

const int N = 5010;
int a[N][N] = { 0 };//原数组
int sum[N][N] = { 0 };//前缀和数组

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y, v;
	cin >> n >> m;
	while (n--)
	{
		cin >> x >> y >> v;
		a[x + 1][y + 1] += v;//同一个位置可能多次放目标，所以应该为累加，而不是直接赋值;数组从(1,1)位置开始便于求前缀和
	}
	//因为不知道x,y具体为多少，所以直接按x,y范围最大值构建前缀和
	for (int i = 1; i <= 5001; i++)
	{
		for (int j = 1; j <= 5001; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	int maxv = 0;//记录价值最大值
		for (int x1 = 1; x1 <= 5001; x1++)
		{
			for (int y1 = 1; y1 <= 5001; y1++)
			{
				int x2 = min(x1 + m - 1,5001);//如果x2 > 5001则直接以5001做为右下角横坐标，y2同理
				int y2 = min(y1 + m - 1,5001);
				int ret = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];//(x1,y1)为左上角，(x2,y2)为右下角矩形所有元素值的和
				if (ret > maxv)
				{
					maxv = ret;
				}
			}
		}
	cout << maxv;
	return 0;
}