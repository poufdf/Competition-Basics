#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>

using namespace std;

const int N = 1e6 + 10;
int a[N] = { 0 };


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int l = 1;
		int r = 1;
		unordered_map<int, int> mp;
		int size = 0;
		while (r <= n)
		{
			mp[a[r]]++;
			while (mp[a[r]] > 1)
			{
				mp[a[l]]--;
				l++;
			}
			size = max(size, r - l + 1);
			r++;
		}
		cout << size<<endl;
	}
	return 0;
}