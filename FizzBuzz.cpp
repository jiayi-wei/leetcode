#include<string>
#include<vector>
#include<iostream>

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> result;
	for (int i = 1; i<n + 1; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			result.push_back("FizzBuzz");
		else if (i % 3 == 0)
			result.push_back("Fizz");
		else if (i % 5 == 0)
			result.push_back("Buzz");
		else
		{
			int count = i;
			string s= "";
			do{
				int digit = count % 10;
				s.insert(s.begin(), char('0' + digit));
				count = count / 10;
			} while (count > 0);
			result.push_back(string(s));
		}
	}
	return result;
}

void main()
{
	int n = 15;
	vector<string> sc = fizzBuzz(n);
	system("pause");
}