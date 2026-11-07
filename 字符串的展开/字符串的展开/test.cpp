#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool Isnum(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Islet(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return true;
	}
	else
	{
		return false;
	}
}



int main()
{
	int p1, p2, p3;
	string s1;
	string s2;
	cin >> p1 >> p2 >> p3 >> s1;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != '-')
		{
			s2 += s1[i];
		}
		else if (s1[i] == '-' && (i == 0 || i == s1.size() - 1))
		{
			s2 += s1[i];
		}
		else
		{
			char l = s1[i - 1];
			char r = s1[i + 1];
			if (r <= l)
			{
				s2 += s1[i];
			}
			else
			{
				if (r == l + 1)
				{
					continue;
				}
				else
				{
					string s3;
					if (Isnum(l) && Isnum(r))
					{
						for (char i = l + 1; i < r; i++)
						{
							if (p1 == 3)
							{
								for (int j = 0; j < p2; j++)
								{
									s3 += '*';
								}
							}
							else
							{
								for (int j = 0; j < p2; j++)
								{
									s3 += i;
								}
							}

						}
						if (p3 == 2)
						{
							reverse(s3.begin(), s3.end());
						}
						s2 += s3;
					}
					else if (Islet(l) && Islet(r))
					{
						if (p1 == 1)
						{
							for (char i = l + 1; i < r; i++)
							{
								for (int j = 0; j < p2; j++)
								{
									s3 += i;
								}
							}

						}
						else if (p1 == 2)
						{
							for (char i = l + 1; i < r; i++)
							{
								for (int j = 0; j < p2; j++)
								{
									s3 += i-32;
								}
							}
						}
						else 
						{
							for (char i = l + 1; i < r; i++)
							{
								for (int j = 0; j < p2; j++)
								{
									s3 += '*';
								}
							}
						}
						if (p3 == 2)
						{
							reverse(s3.begin(), s3.end());
						}
						s2 += s3;
					}
					else
					{
						s2 += s1[i];
					}
				}
			}
		}
	}
	cout << s2;
	return 0;
}




//错误的代码
//bool Isnum(char ch)
//{
//	if (ch >= '0' && ch <= '9')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Islet(char ch)
//{
//	if (ch >= 'a' && ch <= 'z')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//
//int main()
//{
//	int p1, p2, p3;
//	string s1;
//	string s2;
//	cin >> p1 >> p2 >> p3 >> s1;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] != '-' || i==0 || i ==s1.size()-1)
//		{
//			s2 += s1[i];
//		}
//		else
//		{
//			char l = s1[i - 1];
//			char r = s1[i + 1];
//			if (r <= l)
//			{
//				s2 += s1[i];
//			}
//			else
//			{
//				if (r == l + 1)
//				{
//					continue;
//				}
//				else
//				{
//					string s3;
//					if (Isnum(l) && Isnum(r))
//					{
//						for (char i = l + 1; i < r; i++)
//						{
//							for (int i = 0; i < p2; i++)
//							{
//								if (p1 == 3)
//								{
//									s3 += '*';
//								}
//								else
//								{
//									s3 += i;
//								}
//							}
//						}
//						if (p3 == 2)
//						{
//							reverse(s3.begin(), s3.end());
//						}
//						s2 += s3;
//					}
//					else if (Islet(l) && Islet(r))
//					{
//						if (p1 == 1)
//						{
//							for (char i = l + 1; i < r; i++)
//							{
//								for (int i = 0; i < p2; i++)
//								{
//									s3 += i;
//								}
//							}
//							if (p3 == 2)
//							{
//								reverse(s3.begin(), s3.end());
//							}
//							s2 += s3;
//						}
//						if (p1 == 2)
//						{
//							for (char i = l + 1; i < r; i++)
//							{
//								
//								for (int i = 0; i < p2; i++)
//								{
//									s3 += i-32;
//								}
//								
//							}
//							if (p3 == 2)
//							{
//								reverse(s3.begin(), s3.end());
//							}
//							s2 += s3;
//						}
//						if (p1 == 3)
//						{
//							for (int i = 0; i < p2; i++)
//							{
//								s3 += '*';
//							}
//							s2 += s3;
//						}
//					}
//					else
//					{
//						s2 += s1[i];
//					}
//				}
//			}
//		}
//	}
//	std::cout <<  s2;
//	return 0;
//}


//int main()
//{
//	int p1, p2, p3;
//	cin >> p1 >> p2 >> p3;
//	string s;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '-')
//		{
//			int l = i - 1;
//			int r = i + 1;
//			if (s[r] <= s[l])
//			{
//
//			}
//			else
//			{
//				if (s[r] == s[l] + 1)
//				{
//					s.erase(i, 1);
//				}
//				if (p3 == 1)
//				{
//					if (p1 == 1)
//					{
//						int as = s[r] - s[l];
//						int k = p2;
//						int m = i;
//						s.erase(i, 1);
//						for (int j = 1; j < as; j++)
//						{
//							while (k--)//这里用while循环会改变k,导致后面的k都错了
//							{
//								s.insert(m, 1, s[l]+j);
//								m++;
//							}
//						}
//					}
//					else if (p1 == 2)
//					{
//						if (s[l] >= 'a' && s[l] <= 'z')
//						{
//							int as = s[r] - s[l];
//							int k = p2;
//							int m = i;
//							s.erase(i, 1);
//							for (int j = 1; j < as; j++)
//							{
//								while (k--)
//								{
//									s.insert(m, 1, s[l]+j-32);
//									m++;
//								}
//							}
//						}
//						else
//						{
//							int as = s[r] - s[l];
//							int k = p2;
//							int m = i;
//							s.erase(i, 1);
//							for (int j = 1; j < as; j++)
//							{
//								while (k--)
//								{
//									s.insert(m, 1, s[l]+j);
//									m++;
//								}
//							}
//						}
//
//					}
//					else
//					{
//						int as = s[r] - s[l];
//						int k = p2;
//						int m = i;
//						s.erase(i, 1);
//						for (int j = 1; j < as; j++)
//						{
//							s.insert(m, 1, '*');
//							m++;
//						}
//					}
//
//				}
//				else
//				{
//					if (p1 == 1)
//					{
//						int as = s[r] - s[l];
//						int k = p2;
//						int m = i;
//						s.erase(i, 1);
//						for (int j = as - 1; j >= as; j--)
//						{
//							while (k--)
//							{
//								s.insert(m, 1, s[l]+j);
//								m++;
//							}
//						}
//					}
//					else if (p1 == 2)
//					{
//						if (s[l] >= 'a' && s[l] <= 'z')
//						{
//							int as = s[r] - s[l];
//							int k = p2;
//							int m = i;
//							s.erase(i, 1);
//							for (int j = 1; j < as; j++)
//							{
//								while (k--)
//								{
//									s.insert(m, 1, s[l]+j-32);
//									m++;
//								}
//							}
//						}
//						else
//						{
//							int as = s[r] - s[l];
//							int k = p2;
//							int m = i;
//							s.erase(i, 1);
//							for (int j = 1; j < as; j++)
//							{
//								while (k--)
//								{
//									s.insert(m, 1, s[l]+j);
//									m++;
//								}
//							}
//						}
//					}
//					else
//					{
//						int as = s[r] - s[l];
//						int k = p2;
//						int m = i;
//						s.erase(i, 1);
//						for (int j = 1; j < as; j++)
//						{
//							s.insert(m, 1, '*');
//							m++;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << s;
//
//	return 0;
//}