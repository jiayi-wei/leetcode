#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};


//void createList(ListNode* node, int num)
//{
//	ListNode* p = node;
//	for (int i = 0; i < num; i++)
//	{
//		ListNode* newnode = new ListNode;
//		newnode->val = i;
//		newnode->next = NULL;
//		p->next = newnode;
//		p = newnode;
//	}
//}

void createList1(ListNode* pHead, int num)
{
	ListNode* p = pHead;
	for (int i = 1; i<num; i++)
	{
		ListNode* pNewNode = new ListNode;
		pNewNode->val = i;
		pNewNode->next = NULL;
		p->next = pNewNode;
		p = pNewNode;
	}
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	vector<ListNode*> NodeTable;
	ListNode* node_temp = head;
	while (node_temp->next != NULL)
	{
		NodeTable.push_back(node_temp);
		node_temp = node_temp->next;
	}
	NodeTable.push_back(node_temp);
	if (NodeTable.size() == 1)
		return NULL;
	else if (NodeTable.size() == n)
		return NodeTable[1];
	else
	{
		NodeTable[NodeTable.size() - n - 1]->next = NodeTable[NodeTable.size() - n]->next;
		free(NodeTable[NodeTable.size() - n]);
		return NodeTable[0];
	}
}

void main()
{
	int num = 1;
	ListNode* Head = NULL;
	Head = new ListNode;
	Head->val = 0;
	Head->next = NULL;
	createList1(Head, num);
	removeNthFromEnd(Head, 1);
	for (int i = 0; i < num - 1; i++)
	{
		cout << Head->val << endl;
		Head = Head->next;
	}
	system("pause");
}
