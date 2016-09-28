#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector < vector < int >> threeSum(vector<int>& nums){
	vector<vector<int>> num_fit;
	int vector_size = nums.size();
	sort(nums.begin(), nums.end());
	int first_old=0, second_old=0, third_old=0;
	int num_for_zero;
	bool begin_first = true;
	for (int i = 0; i < vector_size; i++){
		if (nums[i] == first_old&&begin_first==false){
			continue;
		}
		else{
			first_old = nums[i];
			begin_first = false;
		}
		int target = 0 - nums[i];
		for (int j = i + 1, k = vector_size-1; k != j;){
			bool begin_second = true;
			bool begin_third = true;
			int sum_temp = nums[j] + nums[k];
			if (sum_temp == target){
				vector<int> temp = { nums[i], nums[j], nums[k] };
				num_fit.push_back(temp);
				j++;
			}
			else if (sum_temp < target){
				while (begin_second == true){
					int old = nums[j];
					j++;
					if (nums[j] != old){
						begin_second = false;
					}
				}
			}
			else if (sum_temp>target){
				while (begin_third == true){
					int old = nums[k];
					k--;
					if (nums[k] != old){
						begin_third = false;
					}
				}
			}

		}
	}
	return num_fit;
}

void main(){
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>>num_zero=threeSum(nums);
	system("pause");
}