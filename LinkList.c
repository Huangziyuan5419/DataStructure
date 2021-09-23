#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int data;//������
	struct Node* Next;

}NODE, *PNODE; //NODE == struct Node, PNODE == struct Node *

PNODE Create();// ����
void Traverse(PNODE pHead); //����
int IsEmpty(PNODE pHead);// �Ƿ�Ϊ��
int Insert(PNODE pHead, int pos, int val); // ����


int main(void)
{
	PNODE pHead = NULL;// struct Node* pHead = NULL; ͷָ��
	// ����������
	pHead = Create();
	Traverse(pHead);
	int a;
	a = Insert(pHead, 4, 11);
	Traverse(pHead);

}

PNODE Create()
{
	int len = 10; // �����Ч�ڵ�ĸ���
	PNODE pHead = (PNODE) malloc(sizeof(NODE));//��ϵͳ����ռ�
	if (pHead == NULL)
	{
		printf("����ʧ��, ������ֹ\n");
		exit(-1);
	}
	PNODE pTail = pHead;// βָ�룬β�巨�� ptail�������м����
	pTail->Next = NULL;
	pHead->Next = pTail;
	for (int i = 0; i < len; i++)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("����ʧ��, ������ֹ\n");
			exit(-1);
		}
		pNew->data = i;
		pTail->Next = pNew;// �½ڵ�ҵ�ptail����
		pNew->Next = NULL;
		pTail = pNew;// β�ڵ�ı�Ϊ���λ��
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

// ��posǰ������½ڵ�
int Insert(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	// ѭ��ֹͣ��pָ�����λ�õ�ǰ��һ���ڵ�
	while (p != NULL && i < (pos - 1))
	{
		p = p->Next;
		i++;
	}
	if (i > pos - 1 || p == NULL)
		return 0; // ��ʾ����ʧ��
	// ����һ���½ڵ�
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("����ʧ��, ������ֹ\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->Next = p->Next;
	p->Next = pNew;
	return 1;

}