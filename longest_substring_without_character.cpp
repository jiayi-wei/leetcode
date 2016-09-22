#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s){
	string result;
	int counter = 0;
	int begin;
	for (int i = 0; i < s.length();){
		if (result.empty()){
			result.push_back(s[i]);
			begin = i;
			i++;
			if (counter < result.length())
				counter = result.length();
			continue;
		}
		else{
			if (result.find(s[i]) == std::string::npos){
				result.push_back(s[i]);
				i++;
				if (counter < result.length())
					counter = result.length();
			}
			else{
				i = begin + result.find(s[i]) + 1;
				result = "";
			}
		}
	}
	return counter;
}

void main(){
	string s = "aax";
	cout << lengthOfLongestSubstring(s);
	system("pause");
}

