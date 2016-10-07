#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>

using namespace std;

//13ms
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

//更优化的方法
int threeSumClosest_new(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() <= 3)
		return accumulate(nums.begin(), nums.end(), 0);
	sort(nums.begin(), nums.end());
	int sum = nums[0] + nums[1] + nums[2], ret = sum;
	if (sum >= target)
		return sum;
	if ((sum = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3]) <= target)
		return sum;
	
	for (int i = 0, j, k; i < nums.size();)
	{
		if ((sum = nums[i] + nums[i + 1] + nums[i + 2])>target)
		{ 
			if (abs(sum - target) < abs(ret - target))
				ret = sum;
			return ret;
		}
		else if ((sum = nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2]) < target)
		{
			if (abs(sum - target) - abs(ret - target))
				ret = sum;
		}
		else
		{
			j = i + 1;
			k = nums.size() - 1;
			while (k > j)
			{
				if ((sum = nums[i] + nums[j] + nums[k]) == target)
					return target;
				else if (sum > target)
				{
					if (abs(sum - target) < abs(ret - target))
						ret = sum;
					do
					{ 
						k--;
					} while (k > j&&nums[k] == nums[k + 1]);
				}
				else
				{
					if (abs(sum - target) < abs(ret - target))
						ret = sum;
					do
					{
						j++;
					} while (k > j&&nums[j] == nums[j - 1]);
				}
			}
		}
		do
		{
			i++;
		} while (i < nums.size() && nums[i] == nums[i - 1]);
	}
}
void main(){
	vector<int> nums = { 1,1,-1,-1,3 };
	cout << threeSumClosest_new(nums, 3) << endl;
	system("pause");
}