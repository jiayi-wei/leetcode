#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(int x){
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	vector <int> nums;
	while (x > 0){
		nums.push_back(x % 10);
		x = x / 10;
	}
	for (int i = 0; i < nums.size() / 2; i++)
		if (nums[i] != nums[nums.size() - i - 1])
			return false;
	return true;
}

void main(){
	int i = 1221;
	cout << isPalindrome(i) << endl;
	system("pause");
}