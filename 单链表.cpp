#include<iostream>
#include<algorithm>
using namespace std;
struct listnode
{
	int val;
	listnode* next;
	listnode() :val(0), next(nullptr){}
	listnode(int x):val(x){}
	listnode(int x, listnode* y) :val(x), next(y) {};
};
listnode* mergetwosortedlist(listnode* list1, listnode* list2)
{
	listnode* dummy = new listnode(-1);
	listnode* cur = dummy->next;
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val >= list2->val)
		{
			cur->next = list2;
			list2=list2->next;
		}
		else
		{
			cur->next = list1;
			list1 = list1->next;
		}
		cur = cur->next;
	}
	if (list1 != nullptr)cur->next = list1;
	if (list2 != nullptr)cur->next = list2;
	return dummy->next;
}
listnode* deletenode(int n, listnode* list)
{
	listnode* head = new listnode(-1);
	head->next = list;
	listnode* cur = head;
	while (n > 1)
	{
		cur = cur->next;
		n--;
	}
	listnode* temp = cur->next;
	cur->next =cur->next->next;
	delete temp;
	return  head->next;
}
listnode* delnode_end(int n, listnode* list)
{
	listnode* dummy = new listnode(-1);
	dummy->next = list;
	listnode* cur = dummy;
	listnode* fast=dummy;
	listnode* slow=dummy;
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	while (fast->next!=nullptr)
	{
		slow = slow->next;
		fast = fast->next;
	}
	listnode* temp = slow->next;
	slow->next = slow->next->next;
	delete temp;
	return dummy->next;

}
listnode* insert(int n, listnode* list,listnode*node)
{
	listnode* head = new listnode(-1);
	head->next = list;
	listnode* cur = head;
	while (n > 1)
	{
		cur = cur->next;
		n--;
	}
	/*for (int i = 0; i < n - 1; i++)
	{
		cur = cur->next;
	}*/
	node->next = cur->next;
	cur->next = node;
	return head->next;
}
listnode* findval(int val, listnode* list)
{
	/*listnode* cur = list;
	while (cur->val != val&&cur->next!=nullptr)
	{
		cur = cur->next;
	}//会漏掉最后一个节点的检查
	if (cur->next == nullptr)return nullptr;
	return cur;*/
	listnode* cur = list;
	while (cur != nullptr)
	{
		if (cur->val == val)
		{
			return cur;
		}
	}
	return nullptr;
}
listnode* find_n(int n, listnode* list)
{
	if (n < 1 || list == nullptr)return nullptr;
	for (int i = 0; i < n - 1;i++)
	{
		list = list->next;
		if (list == nullptr)
			return nullptr;
	}
	return list;
}
listnode* addToTail(int val, listnode* list)
{
	listnode* head = new listnode(-1);
	head->next =list ;
	listnode* cur = head;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	listnode* newnode=new listnode(val);
	cur->next = newnode;
	return head->next;
}
listnode* addToHead(int val, listnode* list)
{
	listnode* newnode=new listnode(val);
	newnode->next = list;
	return newnode;
}
int main()
{
	
	return 0;
}