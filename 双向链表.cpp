#include<iostream>
#include<algorithm>
using namespace std;
struct DListnode
{
	int val;
	DListnode* prev;
	DListnode* next;
	DListnode() :val(0), prev(nullptr), next(nullptr) {}
	DListnode(int val) :val(val), prev(nullptr), next(nullptr){}
	DListnode(int val,DListnode*prev,DListnode*next):val(val),prev(prev),next(next){}

};
DListnode* mergelist(DListnode* list1, DListnode* list2)
{
	DListnode* head = new DListnode();
	DListnode* cur = head;
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val >= list2->val)
		{
			cur->next = list2;
			list2->prev = cur;//单链表没有
			list2 = list2->next;
		}
		else
		{
			cur->next = list1;
			list1->prev = cur;
			list1 = list1->next;
		}
		cur = cur->next;
	}
	if (list2 != nullptr)
	{
		cur->next = list2;
		list2->prev = cur;
	}
	if (list1 != nullptr)
	{
		cur->next = list1;
		list1->prev = cur;
	}
	DListnode* res = head->next;
	if (res != nullptr)
	{
		res->prev = nullptr;
	}
	delete head;//new出来的节点要删除(防止内存泄露)，与单链表不同的是头prev节点的初始化
	return res;
}
DListnode* findval(DListnode* list, int val)
{
	DListnode* cur = list;
	while (cur!=nullptr)
	{
		if (cur->val == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}
DListnode* findn(int n, DListnode* list)
{
	if (n < 1 || list == nullptr)return nullptr;
	DListnode* cur = list;
	while (n>1)
	{
		cur = cur->next;
		if (cur == nullptr)
		{
			return nullptr;
		}
		n--;
	}
	return cur;
}
DListnode* insert(int n, int val, DListnode* list)//在第n个位置插入
{
	if (list == nullptr)return nullptr;
	DListnode* head = new DListnode();
	head->next = list;
	DListnode* cur = head;
	//DListnode* a; a->val = val;不能直接声明野指针
	DListnode* a = new DListnode(val);
	for (int i = 0; i < n-1; i++)
	{
		cur = cur->next;
	}
	a->next = cur->next;
	cur->next->prev = a;
	cur->next = a;
	a->prev = cur;
	DListnode* b = head->next;
	delete head;
	return b;
}
int main()
{
	return 0;
}