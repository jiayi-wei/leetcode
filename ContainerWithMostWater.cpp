#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxArea(vector <int> &height)
{
	int area = 0, size_of_height = height.size();
	if (size_of_height < 2)
	{
		return 0;
	}
	int i = 0, j = size_of_height - 1;
	while (i < j)
	{
		int temp = (j - i)*min(height[i], height[j]);
		if (temp > area)
		{
			area = temp;
		}
		if (height[i] <= height[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return area;
}