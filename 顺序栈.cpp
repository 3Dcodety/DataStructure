//1.栈结构体:
//一个数组：存数据
//一个栈顶指针 top：标记栈顶位置
//2.基本操作函数:
//初始化栈
//判断栈空
//判断栈满
//入栈（push）
//出栈（pop）
//取栈顶元素
//遍历 / 打印栈

#include<iostream>
#include<algorithm>
using namespace std;
# define Maxsize 20
typedef int SElemtype;
typedef struct
{
	int top;
	SElemtype data[Maxsize];
	//SElemtype* data1;//动态顺序栈
}stack;
void initstack(stack* s)
{
	//s->data1 = (SElemtype*)malloc(Maxsize * sizeof(SElemtype));//动态顺序栈
	//s->data1=new SElemtype[Maxsize];
	s->top = -1;
}
int stack_empty(stack* s)
{
	return s->top == -1;
}
int stack_full(stack* s)
{
	return s->top == Maxsize - 1;
}
int stack_pop(stack* s,SElemtype*a)
{
	if (stack_empty(s))
	{
		cout << "栈空" << endl;
		return 0;
	}
	*a = s->data[s->top--];
	return 1;
}
int stack_push(stack* s, SElemtype e)
{
	if (stack_full(s))
	{
		cout << "栈满" << endl;
		return 0;
	}
	s->data[++s->top] = e;
	return 1;
}
void print1(stack* s)
{
	if (stack_empty(s))
	{
		cout << "栈空"<<endl;
		return;
	}
	for (int i = s->top; i >= 0; i--)
	{
		cout << s->data[i]<<endl;
	}
}
void print0(stack* s)
{
	if (stack_empty(s))
	{
		cout << "栈空" << endl;
		return;
	}
	for (int i = 0; i <= s->top; i++)
	{
		cout << s->data[i] << endl;
	}
}
int get_top(stack* s)
{
	if (stack_empty(s))
	{
		cout << "栈空"<<endl;
		return 0;
	}
	return s->data[s->top];
}
int length(stack* s)
{
	return s->top + 1;
}
void clearstack(stack* s)
{
	s->top = -1;
}
int main()
{
	stack* s=new stack;
	initstack(s);
	stack_push(s, 5);
	for (int i = 0; i < 4; i++)
	{
		stack_push(s, i);
	}
	print1(s);
	cout << length(s);
	return 0;
}