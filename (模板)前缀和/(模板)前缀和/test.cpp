#define _CRT_SECURE_NO_WARNINGS
//https://ac.nowcoder.com/acm/problem/226282
#include<iostream>

using namespace std;

const int N = 1e5 + 10;
//注意数组里值的范围，arr[i]可能达到1e9级别，用int可能会溢出，所以用long long
long long arr[N] = { 0 };//原数组
long long sum[N] = { 0 };//前缀和数组

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }

    return 0;
}