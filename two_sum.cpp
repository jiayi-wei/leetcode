#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct Node{
	int num;
	int elem;
};

bool compare(Node a, Node b){
	return a.elem < b.elem;
}

/*bool Find_num(vector<Node> sequ, int low, int high, int key, Node &pass)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		if (sequ[mid].elem == key)
		{
			pass = sequ[mid];
			return true;
		}
		else if (key < sequ[mid].elem)
			return Find_num(sequ, low, mid - 1, key, pass);
		else
			return Find_num(sequ, mid + 1, high, key, pass);
	}
	else if (low == high)
		if (sequ[low].elem == key)
		{
			pass = sequ[low];
			return true;
		}
	return false;
}*/

vector <int> Two_sum(vector<int> Sequ, int target){
	vector<int> output;
	vector<Node> Array;
	Node temp,pass;
	for (int i = 0; i < Sequ.size(); i++)
	{
		temp.elem = Sequ[i];
		temp.num = i;
		Array.push_back(temp);
	}
	sort(Array.begin(), Array.end(),compare);
	for (int i = 0, j = Array.size() - 1; i != j;)
	{
		int sum_temp = Array[i].elem + Array[j].elem;
		if (sum_temp == target)
		{
			if (Array[i].num < Array[j].num)
			{
				output.push_back(Array[i].num);
				output.push_back(Array[j].num);
			}
			else
			{
				output.push_back(Array[j].num);
				output.push_back(Array[i].num);
			}
			break;
		}
		else if (sum_temp < target)
			i++;
		else if (sum_temp > target)
			j--;
	}
	return output;
}

void main(){
	vector <int> sequ = { 1, 0, 3, -4, 13, -9 };
	int target = 1;
	vector<int> out = Two_sum(sequ, target);
	cout << out[0] << "  " << out[1] << endl;
	system("pause");
}