#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	if (nums1.size() == 1 && nums2.size()==1)
		return ((double)nums1[0] + (double)nums2[0]) / 2;
	double result;
	int num_1 = nums1.size(), num_2 = nums2.size();
	if (nums1.size() == 0){
		if (num_2 % 2 == 1){
			return (double)nums2[num_2 / 2];
		}
		else{
			return ((double)nums2[num_2 / 2] + (double)nums2[num_2 / 2 - 1])/2;
		}
	}
	if (nums2.size() == 0){
		if (num_1 % 2 == 1){
			return (double)nums1[num_1 / 2];
		}
		else{
			return ((double)nums1[num_1 / 2] + (double)nums1[num_1 / 2 - 1]) / 2;
		}
	}
	int media = (num_1 + num_2) / 2;
	int count_1, count_2;
	int m_1 = 0, m_2 = 0;
	int temp;
	int keep_1 = nums1[m_1], keep_2 = nums2[m_2];
	for (int i = 0; i <= media; i++){
		if (keep_1 <= keep_2){
			temp = keep_1;
			if (m_1 == num_1-1){
				m_2++;
				if (m_2<=num_2-1)
					keep_1 = nums2[m_2];
			}
			else{
				if (m_1 <= num_1 - 1){
					m_1++;
					keep_1 = nums1[m_1];
				}
			}
		}
		else{
			temp = keep_2;
			if (m_2 == num_2-1){
				m_1++;
				if (m_1<=num_1-1)
					keep_2 = nums1[m_1];
			}
			else{
				if (m_2 <= num_2 - 1){
					m_2++;
					keep_2 = nums2[m_2];
				}
			}
		}
		if (i % 2 == 0){
			count_1 = temp;
		}
		else{
			count_2 = temp;
		}
	}
	if ((num_1 + num_2) % 2 == 0)
		result = ((double)count_1 + (double)count_2) / 2;
	else if ((num_1 + num_2) % 2 == 1 && (num_1 + num_2) % 4 == 1)
		result = count_1*1.0;
	else
		result = count_2*1.0;
	return result;
}

void main(){
	vector<int> arr1 = { 1 };
	vector<int> arr2 = { 2, 3 };
	cout << findMedianSortedArrays(arr1, arr2) << endl;
	system("pause");
}