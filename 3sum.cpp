#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

//vector < vector < int >> threesum(vector<int>& nums){
//	vector<vector<int>> num_fit;
//	int vector_size = nums.size();
//	sort(nums.begin(), nums.end());
//	int first_old=0, second_old=0, third_old=0;
//	int num_for_zero;
//	bool begin_first = true;
//	for (int i = 0; i < vector_size - 1; i++){
//		if (nums[i] == first_old&&begin_first==false){
//			continue;
//		}
//		else{
//			first_old = nums[i];
//			begin_first = false;
//		}
//		int target = 0 - nums[i];
//		for (int j = i + 1, k = vector_size-1; k > j;){
//			bool begin_second = true;
//			bool begin_third = true;
//			int sum_temp = nums[j] + nums[k];
//			if (sum_temp == target){
//				vector<int> temp = { nums[i], nums[j], nums[k] };
//				num_fit.push_back(temp);
//				if (nums[j] == nums[k]){
//					break;
//				}
//				while (begin_second == true){
//					int old = nums[j];
//					j++;
//					if (nums[j] != old){
//						begin_second = false;
//					}
//				}
//			}
//			else if (sum_temp < target){
//				if (nums[j] == nums[k]){
//					break;
//				}
//				while (begin_second == true){
//					int old = nums[j];
//					j++;
//					if (nums[j] != old){
//						begin_second = false;
//					}
//				}
//			}
//			else if (sum_temp>target){
//				if (nums[j] == nums[k]){
//					break;
//				}
//				while (begin_third == true){
//					int old = nums[k];
//					k--;
//					if (nums[k] != old){
//						begin_third = false;
//					}
//				}
//			}
//
//		}
//	}
//	return num_fit;
//}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); ++k) {
		if (nums[k] > 0) break;
		if (k > 0 && nums[k] == nums[k - 1]) continue;
		int target = 0 - nums[k];
		int i = k + 1, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] == target) {
				res.push_back({ nums[k], nums[i], nums[j] });
				while (i < j && nums[i] == nums[i + 1]) ++i;
				while (i < j && nums[j] == nums[j - 1]) --j;
				++i; --j;
			}
			else if (nums[i] + nums[j] < target) ++i;
			else --j;
		}
	}
	return res;
}

void main(){
	vector<int> nums = { 0, 0, 0 };
	vector<vector<int>>num_zero=threeSum(nums);
	system("pause");
}