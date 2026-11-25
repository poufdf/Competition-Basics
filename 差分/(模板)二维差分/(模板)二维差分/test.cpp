#define _CRT_SECURE_NO_WARNINGS
// https ://ac.nowcoder.com/acm/problem/226337
#include<iostream>

using namespace std;
const int N = 1000 + 10;
long long a[N][N];
long long dif[N][N];

//二维差分数组的核心处理逻辑
void update(int x1, int y1, int x2, int y2, int k)
{
    dif[x1][y1] += k;
    dif[x1][y2 + 1] -= k;
    dif[x2 + 1][y1] -= k;
    dif[x2 + 1][y2 + 1] += k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    //为什么这里不直接插入到原数组，而要用差分数组的性质插入
    //因为要用差分数组的前缀和得到原数组,原数组相当于在以(i,j)为左上角，(i,j)为右下角的区域+k
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            update(i, j, i, j, x);//重复逻辑封装成一个函数
            //dif[i][j] += x;
            //dif[i][j + 1] -= x;
            //dif[i + 1][j] -= x;
            //dif[i + 1][j + 1] += x;
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        update(x1, y1, x2, y2, k);
        //dif[x1][y1] += k;
        //dif[x1][y2 + 1] -= k;
        //dif[x2 + 1][y1] -= k;
        //dif[x2 + 1][y2 + 1] += k;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + dif[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}















//#include<iostream>
//using namespace std;
//const int N = 1000 + 10;
//long long a[N][N];
//long long dif[N][N];
//
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int n, m, q;
//    cin >> n >> m >> q;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            int x;
//            cin >> x;
//            dif[i][j] += x;
//            dif[i][j + 1] -= x;
//            dif[i + 1][j] -= x;
//            dif[i + 1][j + 1] += x;
//        }
//    }
//    while (q--)
//    {
//        int x1, y1, x2, y2, k;
//        cin >> x1 >> y1 >> x2 >> y2 >> k;
//        dif[x1][y1] += k;
//        dif[x1][y2 + 1] -= k;
//        dif[x2 + 1][y1] -= k;
//        dif[x2 + 1][y2 + 1] += k;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + dif[i][j];
//        }
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cout << a[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//
//    return 0;
//}