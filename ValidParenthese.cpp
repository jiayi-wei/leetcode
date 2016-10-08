#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValid(string s)
{
	vector<int>flag;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			flag.push_back(1);
		else if (s[i] == '[')
			flag.push_back(2);
		else if (s[i] == '{')
			flag.push_back(3);
		else if (s[i] == ')')
		{
			if (flag.empty() || flag.back() != 1)
				return false;
			else
				flag.pop_back();
		}
		else if (s[i] == ']')
		{
			if (flag.empty() || flag.back() != 2)
				return false;
			else
				flag.pop_back();
		}
		else if (s[i] == '}')
		{
			if (flag.empty() || flag.back() != 3)
				return false;
			else
				flag.pop_back();
		}
	}
	if (flag.empty())
		return true;
	else
		return false;
}