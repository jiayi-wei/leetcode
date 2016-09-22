#include<string>
#include<iostream>
#include<vector>

using namespace std;

string convert(string s, int numRows){
	if (numRows == 1)
		return s;
	string s_new;
	vector <vector<char>> Mat(numRows);
	int nn = 0;
	for (int i = 0, j = 0; j < s.length(); i++)
	{
		int tmp = i%numRows;
		int tmp_con;
		if ((i/numRows)%2==0)
			Mat[tmp].push_back(s[j++]);
		else
		{
			tmp_con = numRows - 1 - tmp;
			if (tmp_con == 0 || tmp_con == numRows - 1)
				Mat[tmp_con].push_back('*');
			else
				Mat[tmp_con].push_back(s[j++]);
		}
	}
	for (int i = 0; i < numRows; i++)
	{
		string tmp_str;
		if (i == 0 || i == numRows - 1)
			for (int j = 0; j < Mat[i].size(); j += 2)
			{
				tmp_str = Mat[i][j];
				s_new += tmp_str;
			}
		else
			for (int j = 0; j < Mat[i].size(); j++)
			{
				tmp_str = Mat[i][j];
				s_new += tmp_str;
			}
	}
	return s_new;
}

void main(){
	string s = "PAHNAPLSIIGYIRADFVFGS";
	int rows = 5;
	string s_new;
	int tmp = 10;
	vector <vector <char>> Mat(rows);
	s_new=convert(s, rows);
	cout << s_new << endl;
	system("pause");
}