#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
	int target_out,differ;
	int temp_target, temp = INT_MAX;;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-2; i++)
	{
		temp_target = target - nums[i];
		/*int temp_diff = INT_MAX;*/
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			differ = temp_target - nums[j] - nums[k];
			/*if (abs_differ < temp_diff)
				temp_diff = abs_differ;
			else
				break;*/
			if (abs(differ) < temp)
			{
				temp = abs(differ);
				target_out = nums[i] + nums[j] + nums[k];
			}
			if (differ < 0)
			{
				k--;
			}
			else if (differ > 0)
			{
				j++;
			}
			else
			{
				break;
			}
		}
	}
	return target_out;
}

void main(){
	vector<int> nums = { 0,2,1,-3 };
	cout << threeSumClosest(nums, 1) << endl;
	system("pause");
}