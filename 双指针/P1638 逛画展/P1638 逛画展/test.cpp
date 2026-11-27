#define _CRT_SECURE_NO_WARNINGS
//https ://www.luogu.com.cn/problem/P1638
#include<iostream>

using namespace std;
const int N = 1e6 + 10;
int a[N];
int mp[N];//记录每一个画家出现的次数

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int count = 0;//当count == m时，说明此时子数组中已经有了m位画家
	int x = 0;
	int y = 0;
	int price = n + 10;//不能恰好等于n,不然存在一种情况当len也为n时，第34行的判断进不去
	int left = 1;
	int right = 1;
	while (right <= n)
	{
		mp[a[right]]++;
		if (mp[a[right]] == 1)//当画家第一次出现在子数组中时，count++
		{
			count++;
		}
		while (count == m)//当m位画家都在子数组中时，更新left
		{
			int len = right - left + 1;
			if (len < price)
			{
				price = len;
				x = left;
				y = right;
			}
			mp[a[left]]--;
			if (mp[a[left]] == 0)
			{
				count--;
			}
			left++;
		}
		right++;
	}
	cout << x << ' ' << y;

	return 0;
}


//自己第一遍写的代码，在判断子数组中是否有m位画家时用了笨方法，也就是循环子数组，导致了超时
//#include<iostream>
//#include<unordered_map>
//
//using namespace std;
//const int N = 1e6 + 10;
//int a[N];
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	unordered_map<int, int> mp;
//	int left = 1;
//	int right = 1;
//	int price = 1e4;
//	int x = 0;
//	int y = 0;
//	//for (int i = 1; i <= m; i++)
//	//{
//	//	mp[i] = 0;
//	//}
//	while (right <= n)
//	{
//		for (int i = 1; i <= m; i++)
//		{
//			while (mp[i] == 0)
//			{
//				mp[a[right]]++;
//				if (mp[i] != 0)
//				{
//					break;
//				}
//				right++;
//				if (right > n)
//				{
//					break;
//				}
//			}
//		}
//		if (right > n)
//		{
//			break;
//		}
//		if ((right - left + 1) < price)
//		{
//			price = right - left + 1;
//			x = left;
//			y = right;
//			
//		}
//		mp[a[left]]--;
//		left++;
//	}
//	cout << x << ' ' << y;
//
//	return 0;
//}