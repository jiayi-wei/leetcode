#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> nums)
{
	ListNode dummy(-1);
	ListNode* p = &dummy;
	for (int i = 0; i < nums.size(); i++)
	{
		ListNode* ptemp;
		ptemp = (ListNode*)malloc(sizeof(ListNode));
		ptemp->val = nums[i];
		ptemp->next = NULL;
		p->next = ptemp;
		p = ptemp;
	}
	return dummy.next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	ListNode head(-1);
	ListNode *p = &head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}
	}

	if (l1 == NULL)
		p->next = l2;
	else 
		p->next = l1;
	return head.next;
}

void main()
{
	vector<int> nums1 = {1};
	vector<int> nums2 = {2};
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	ListNode* head1 = createList(nums1);
	ListNode* head2 = createList(nums2);
	
	ListNode* headnew = mergeTwoLists(head1, head2);
	

	system("pause");
}