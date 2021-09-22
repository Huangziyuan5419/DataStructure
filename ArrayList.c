#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxLenth 4
typedef int ElemType;

// 顺序表
typedef struct Arr
{
	int* pBase; //描述数组元素的第一个地址
	int len;//描述数组的长度
	int cnt;//当前数组有效元素的个数

}Array;


void Create(Array* pArr, int lenth);//初始化
int Append(Array* pArr, int val);//向顺序表末尾追加
int Insert(Array* pArr, int pos, int val);//插入
int Delete(Array* pArr, int pos);//删除表元素
int IsEmpty(Array* pArr);//是否为空
int IsFull(Array* pArr);//是否为满
void Show(Array* pArr); //显示表元素


int main()
{
	int val; //表示被删元素的值
	Array arr;//定义一个结构体变量
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
		printf("动态分配失败！\n");
		exit(-1);
	}
	else
	{
		printf("动态分配成功！\n");
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
		return 1;//1表示为空
	else
		return 0;//表示非空
}

int IsFull(Array* pArr)
{
	if (pArr->cnt == pArr->len)
		return 1; //1表示表满
	else
		return 0;
}



void Show(Array* pArr)
{
	if (IsEmpty(pArr))
	{
		printf("该表为空");
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

int Insert(Array* pArr, int pos, int val)//插入元素，在pos前面插入，pos从1开始
{
	if (IsFull(pArr))
	{
		printf("表满\n");
		return 0;
	}
		
	if (pos<1 || pos > pArr->cnt + 1)//插入位置不合法
	{
		printf("插入位置非法\n");
		return 0; // 表示插入失败
	}

	for (int i = pArr->cnt - 1; i >= pos - 1; i--)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	return 1;

}

int Delete(Array* pArr, int pos, int* val)//删除表元素
{
	if (IsEmpty(pArr))
	{
		printf("该表为空");
		return 0;
	}

	if (pos<1 || pos > pArr->cnt)//删除元素位置不合法
	{
		printf("删除元素位置不合法\n");
		return 0; // 表示删除失败
	}
	*val = pArr->pBase[pos - 1];
	for (int i = pos; i <= pArr->cnt-1; i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return 1;
}
