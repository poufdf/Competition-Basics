#define _CRT_SECURE_NO_WARNINGS

//https://ac.nowcoder.com/acm/problem/226303
#include<iostream>

using namespace std;

const int N = 1e5 + 10;
long long arr[N] = { 0 };
long long dif[N] = { 0 };


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dif[i] = arr[i] - arr[i - 1];
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        dif[l] += k;
        dif[r + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + dif[i];
        cout << arr[i] << ' ';
    }

    return 0;
}