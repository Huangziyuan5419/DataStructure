#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxLenth 4
typedef int ElemType;

// ˳���
typedef struct Arr
{
	int* pBase; //��������Ԫ�صĵ�һ����ַ
	int len;//��������ĳ���
	int cnt;//��ǰ������ЧԪ�صĸ���

}Array;


void Create(Array* pArr, int lenth);//��ʼ��
int Append(Array* pArr, int val);//��˳���ĩβ׷��
int Insert(Array* pArr, int pos, int val);//����
int Delete(Array* pArr, int pos);//ɾ����Ԫ��
int IsEmpty(Array* pArr);//�Ƿ�Ϊ��
int IsFull(Array* pArr);//�Ƿ�Ϊ��
void Show(Array* pArr); //��ʾ��Ԫ��


int main()
{
	int val; //��ʾ��ɾԪ�ص�ֵ
	Array arr;//����һ���ṹ�����
	Create(&arr, MaxLenth);
	Append(&arr, 1);
	Append(&arr, 3);
	Append(&arr, 4);
	Append(&arr, 6);
	Show(&arr);
	Insert(&arr, 2, 2);
	Show(&arr);

}

void Create(Array* pArr, int lenth)
{
	pArr->pBase = (int*)(malloc(sizeof(int) * lenth));
	if (pArr->pBase ==NULL)
	{
		printf("��̬����ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf("��̬����ɹ���\n");
		pArr->len = lenth;
		pArr->cnt = 0;
	}
	return;

}

int Append(Array* pArr, int val)
{
	pArr->pBase[(pArr->cnt)] = val;
	pArr->cnt++;
	return 1;
}

int IsEmpty(Array* pArr)
{
	if (pArr->cnt == 0)
		return 1;//1��ʾΪ��
	else
		return 0;//��ʾ�ǿ�
}

int IsFull(Array* pArr)
{
	if (pArr->cnt == pArr->len)
		return 1; //1��ʾ����
	else
		return 0;
}



void Show(Array* pArr)
{
	if (IsEmpty(pArr))
	{
		printf("�ñ�Ϊ��");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("%d \t", pArr->pBase[i]);
		}
		printf("\n");
	}
	
}

int Insert(Array* pArr, int pos, int val)//����Ԫ�أ���posǰ����룬pos��1��ʼ
{
	if (IsFull(pArr))
	{
		printf("����\n");
		return 0;
	}
		
	if (pos<1 || pos > pArr->cnt + 1)//����λ�ò��Ϸ�
	{
		printf("����λ�÷Ƿ�\n");
		return 0; // ��ʾ����ʧ��
	}

	for (int i = pArr->cnt - 1; i >= pos - 1; i--)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	return 1;

}

int Delete(Array* pArr, int pos, int* val)//ɾ����Ԫ��
{
	if (IsEmpty(pArr))
	{
		printf("�ñ�Ϊ��");
		return 0;
	}

	if (pos<1 || pos > pArr->cnt)//ɾ��Ԫ��λ�ò��Ϸ�
	{
		printf("ɾ��Ԫ��λ�ò��Ϸ�\n");
		return 0; // ��ʾɾ��ʧ��
	}
	*val = pArr->pBase[pos - 1];
	for (int i = pos; i <= pArr->cnt-1; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return 1;
}