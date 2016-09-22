#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
	if (-10 < x && x < 10)
		return x;
	int x_new=0, num = 1;
	int limit[9] = { 2, 1, 4, 7, 4, 8, 3, 6, 4 };
	bool plus=true;
	if (x < 0){
		x = 0-x;
		plus = false;
	}
	vector<int> nums;
	vector<int> tens;
	while (x > 0){
		tens.push_back(num);
		int tmp = x % 10;
		nums.push_back(tmp);
		x = x/10;
		num = num * 10;
	}
	if (nums.size()==10)
		for (int i = 0; i < 9; i++){
			if (limit[i] < nums[i])
				return 0;
			else if (limit[i] > nums[i])
				break;
		}
	for (int i = 0; i < nums.size(); i++){
		x_new += nums[i] * tens[tens.size() - 1 - i];
	}
	if (plus == false)
		x_new = 0-x_new;
	return x_new;
}

void main(){
	int i = 1563847412;
	cout << reverse(i) << endl;
	system("pause");
}