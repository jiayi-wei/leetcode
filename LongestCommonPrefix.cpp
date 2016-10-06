#include<string>
#include<iostream>
#include<vector>

using namespace std;

//string longestCommonPrefix(vector<string>& strs)
//{
//	if (strs.size() == 1)
//		return strs[0];
//	string common = "";
//	if (strs.size() == 0)
//		return common;
//	int len = strs[0].length(), num = 0;
//	for (int i = 1; i < strs.size(); i++)
//	{
//		if (strs[i].length() < len)
//		{
//			len = strs[i].length();
//			num = i;
//		}
//	}
//
//	bool contain = true;
//	for (int i = 0; i < len; i++)
//	{
//		char temp_ch = strs[num][i];
//		for (int j = 0; j < strs.size(); j++)
//		{
//			if (j == num)
//				continue;
//			if (strs[j][i] == temp_ch)
//				continue;
//			else
//			{
//				contain = false;
//				break;
//			}
//		}
//		if (contain)
//			common += temp_ch;
//		else
//			break;
//	}
//	return common;
//}

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 1)
		return strs[0];

	if (strs.size() == 0)
		return "";

	for (int i = 0; i < strs[0].length(); i++)
	{
		char temp_ch = strs[0][i];
		for (int j = 0; j < strs.size(); j++)
		{
			if (strs[j][i] == temp_ch)
				continue;
			else
				return strs[0].substr(0, i);
		}
	}
	return strs[0];
}

void main()
{
	vector <string> strs = { "a", "b" };
	cout << longestCommonPrefix(strs) << endl;
	system("pause");
}