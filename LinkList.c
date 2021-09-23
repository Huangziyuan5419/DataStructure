#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;//数据域
	struct Node* Next;

}NODE, *PNODE; //NODE == struct Node, PNODE == struct Node *

PNODE Create();// 创建
void Traverse(PNODE pHead); //遍历
int IsEmpty(PNODE pHead);// 是否为空
int Insert(PNODE pHead, int pos, int val); // 插入


int main(void)
{
	PNODE pHead = NULL;// struct Node* pHead = NULL; 头指针
	// 创建单链表
	pHead = Create();
	Traverse(pHead);
	int a;
	a = Insert(pHead, 4, 11);
	Traverse(pHead);

}

PNODE Create()
{
	int len = 10; // 存放有效节点的个数
	PNODE pHead = (PNODE) malloc(sizeof(NODE));//向系统申请空间
	if (pHead == NULL)
	{
		printf("申请失败, 程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;// 尾指针，尾插法， ptail类似与中间变量
	pTail->Next = NULL;
	pHead->Next = pTail;
	for (int i = 0; i < len; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("申请失败, 程序终止\n");
			exit(-1);
		}
		pNew->data = i;
		pTail->Next = pNew;// 新节点挂到ptail上面
		pNew->Next = NULL;
		pTail = pNew;// 尾节点改变为最后位置
	}
	return pHead;
}


void Traverse(PNODE pHead)
{
	PNODE p = pHead->Next;
	while (p != NULL)
	{
		printf("%d \t", p->data);
		p = p->Next;
	}
	printf("\n");
}
int IsEmpty(PNODE pHead)
{
	if (pHead->Next == NULL)
		return 1;
	else
		return 0;
}

// 在pos前面插入新节点
int Insert(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	// 循环停止，p指向插入位置的前面一个节点
	while (p != NULL && i < (pos - 1))
	{
		p = p->Next;
		i++;
	}
	if (i > pos - 1 || p == NULL)
		return 0; // 表示插入失败
	// 申请一个新节点
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("申请失败, 程序终止\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->Next = p->Next;
	p->Next = pNew;
	return 1;

}