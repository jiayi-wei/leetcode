#include<iostream>
#include<string>

using namespace std;

//bool isMatch(string s, string p)
//{
//	int s_length = s.length(), p_length = p.length();
//	if (s == p)
//	{
//		return true;
//	}
//
//	if (p[0] == NULL)
//	{
//		return s[0] == NULL;
//	}
//	else if (p[1] == '*')
//	{
//		while ((s[0] == p[0] || p[0] == '.') && s_length > 0)
//		{
//			if (isMatch(s, p.substr(2, p_length - 2)))
//			{
//				return true;
//			}
//			s = s.substr(1, s_length - 1);
//			s_length = s.length();
//		}
//		return isMatch(s, p.substr(2, p_length - 2));
//	}
//	else
//	{
//		if ((s[0] == p[0] || p[0] == '.') && s_length > 0)
//		{
//			return isMatch(s.substr(1, s_length - 1), p.substr(1, p_length - 1));
//		}
//		else
//		{
//			return false;
//		}
//	}
//}

bool isMatch(string s, string p)
{
	return isMatchChar(s.c_str(), p.c_str());
}

bool isMatchChar(const char* s, const char* p)
{
	if (*p == '\0')
	{
		return *s == '\0';
	}
	else if (*(p + 1) != '*')
	{
		if ((*s == *p || *p == '.') && *s != '\0')
		{
			return isMatchChar(s + 1, p + 1);
		}
		return false;
	}
	else
	{
		while ((*s == *p || *p == '.') && *s != '\0')
		{
			if (isMatchChar(s, p + 2))
			{
				return true;
			}
			s++;
		}
		return isMatchChar(s, p + 2);
	}
}

//void  simpleStr(string & s)
//{
//	bool anyChar = false;
//	int i = 0, flag = -1, curAny = -1;
//	while (i + 1 < s.size())
//	{
//		if (s[i + 1] == '*')
//		{
//			if (flag == -1)
//			{
//				flag = i;
//			}
//			if (anyChar && i != curAny)
//			{
//				s.erase(i, 2);
//				if (i < curAny)
//				{
//					curAny -= 2;
//				}
//			}
//			else if (!anyChar && s[i] == '.')
//			{
//				anyChar = true;
//				curAny = i;
//				i = flag;
//			}
//			else if (!anyChar && i + 3 < s.size() && s[i + 3] == '*' && s[i] == s[i + 2])
//			{
//				s.erase(i, 2);
//			}
//			else
//			{
//				i += 2;
//			}
//		}
//		else
//		{
//			anyChar = false;
//			flag = -1;
//			curAny = -1;
//			i++;
//		}
//	}
//}
//
//bool isRecursiveMatch(string s, string p) {
//	int i = 0, j = 0;
//	if (p.size() == 0)
//	{
//		return (s.size() == 0);
//	}
//	bool anyChar = false;
//
//	i = 0; j = 0;
//	while (i < s.size() || j < p.size())
//	{
//		anyChar = false;
//		if (j >= p.size())
//		{
//			return (i >= s.size());
//		}
//
//		if (p[j] == '.')
//		{
//			anyChar = true;
//		}
//		if (j + 1 < p.size() && p[j + 1] == '*')
//		{
//			int tempi = i;
//			while (tempi < s.size())
//			{
//				if (isRecursiveMatch(s.substr(tempi), p.substr(j + 2)))
//				{
//					return true;
//				}
//				if (!anyChar && s[tempi] != p[j])
//				{
//					i = tempi - 1;
//					break;
//				}
//				tempi++;
//			}
//			if (tempi == s.size())
//			{
//				return isRecursiveMatch("", p.substr(j + 2));
//			}
//			i++;
//		}
//		else
//		{
//			if (i >= s.size() || (!anyChar && s[i] != p[j]))
//			{
//				return false;
//			}
//		}
//
//		i++;
//		j++;
//	}
//	return true;
//}


void main()
{
	string s = "a";
	string p = ".*..a*";
	cout << isMatch(s, p) << endl;
	system("pause");
}