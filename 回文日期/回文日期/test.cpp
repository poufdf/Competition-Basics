#define _CRT_SECURE_NO_WARNINGS
//https://www.luogu.com.cn/problem/P2010

//确认枚举的对象很重要，因为日期是唯一的，所以一个日期的回文只有一个年对应。
//比如12月31日的年回文只有1321，对应的数字13211231是唯一的
//所以只要枚举完所有日期判断是否在范围里就可以了
#include<iostream>

using namespace std;

int date1, date2;
int day[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int count = 0;
	cin >> date1 >> date2;
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <=day[i]; j++)
		{
			int year = j % 10 * 1000 + j / 10 * 100 + i % 10 * 10 + i / 10;
			int date3 = year * 10000 + i * 100 + j;
			if (date3 >= date1 && date3 <= date2)
			{
				count++;
			}
		}
	}
	cout << count;
	return 0;
}

//时间复杂度较高，一部分测试用例过不了
//#include<iostream>
//#include<string>
//using namespace std;
//
//bool Ispd(string s)
//{
//	int l=0;
//	int r=s.size()-1; 
//	while (s[l] == s[r] && l < r)
//	{
//		l++;
//		r--;
//	}
//	if (l > r)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//
//
//}
//bool Isleapyear(string s)
//{
//	int year = stoi(s);
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//
//}
//
//int main()
//{
//	string s1, s2, s3;
//	int count = 0;
//	string date1;
//	string date2;
//	cin >>date1>>date2;
//	s1 = date1.substr(0, 4);
//	s2 = date1.substr(4, 2);
//	s3 = date1.substr(6, 2);
//	if (Ispd(date1))
//	{
//		count++;
//	}
//	while (date1 != date2)
//	{	
//		int m = 0;
//		s3 += 1;
//		if (s2 == "02")
//		{
//			if (Isleapyear(s1))
//			{
//				if (s3 > "29")
//				{
//					m = 1;
//				}
//			}
//			else
//			{
//				if (s3 > "28")
//				{
//					m = 1;
//				}
//			}
//		}
//		else if (s2 == "01" || s2 == "03" || s2 == "05" || s2 == "07" || s2 == "08" || s2 == "10" || s2 == "12")
//		{
//			if (s3 > "31")
//			{
//				m = 1;
//			}
//		}
//		else
//		{
//			if (s3 > "30")
//			{
//				m = 1;
//			}
//		}
//		if (m == 1)
//		{
//			s3 = "01";
//			s2 += 1;
//			if (s2 > "12")
//			{
//				s1 += 1;
//				s2 = "01";
//			}
//			
//		}
//		date1 = s1 + s2 + s3;
//		if (Ispd(date1))
//		{
//			count++;
//		}
//	}
//	cout << count;
//	return 0;
//}