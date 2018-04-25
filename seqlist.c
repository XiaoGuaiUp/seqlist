#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
#include "seqlist.h"

//顺序表初始化
void SeqListInit(SeqList * seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	seqlist->size = 0;
}

//往顺序表尾部插入元素value
void SeqListPushBack(SeqList * seqlist, SeqListType value)
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{
		//顺序表已满
		return;
	}
	seqlist->data[seqlist->size]= value;
	seqlist->size++;
}

//
void SeqListPopBack(SeqList *seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{//顺序表是空
		return;
	}
	--seqlist->size;
	return;
}

void SeqListPushFront(SeqList *seqlist, SeqListType value)//头插
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{//满了
		return;
	}
	//++seqlist->size;
	seqlist->size++;
	size_t i = seqlist->size - 1;
	/*for (; i > 0; --i)
	{
		seqlist->data[i] = seqlist->data[i - 1];
	}*/
	for (; i > 0; i--)
	{
		seqlist->data[i] = seqlist->data[i - 1];
	}
	seqlist->data[0] = value;
	return;
}

void SeqListPopFront(SeqList *seqlist)//头删
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{//空
		return;
	}
	size_t i = 0;
	for (; i < seqlist->size - 1; ++i)
	{
		seqlist->data[i] = seqlist->data[i + 1];
	}
	--seqlist->size;
	return;
}

void SeqListInsert(SeqList *seqlist, size_t pos, SeqListType value)//在pos位置插入value元素
{
	if (seqlist == NULL)
	{
		return;
	}
	if (pos >= seqlist->size)
	{//越界了
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{//满了
		return;
	}
	if (pos == 0)
	{//如果pos=0时，后面的--i为-1时，size_t是无符号长整型，负数为一个超级大的数值
		//故转为头插函数
		SeqListPushFront(&seqlist, value);
	}
	++seqlist->size;
	size_t i = seqlist->size - 1;
	for (; i - 1 >= pos; --i)
	{
		seqlist->data[i] = seqlist->data[i - 1];
	}
	seqlist->data[pos] = value;
	return;
}

void SeqListErase(SeqList *seqlist, size_t pos)//删除pos位置的元素
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{//空
		return;
	}
	if (pos >= seqlist->size)
	{//pos值越界
		return;
	}
	size_t i = pos;
	for (; i < seqlist->size - 1; ++i)
	{
		seqlist->data[i] = seqlist->data[i + 1];
	}
	--seqlist->size;
	return;
}

void SeqListRead(SeqList *seqlist, size_t pos)//读取pos位置的元素
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{
		return;
	}

	printf("[%c]\n", seqlist->data[pos]);
}

void SeqListAlter(SeqList *seqlist, size_t pos, SeqListType value)//更改pos位置处的元素为value
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{
		return;
	}
	seqlist->data[pos] = value;
}

size_t SeqListFindIndex(SeqList*seqlist, SeqListType value)//查找元素value的下标
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{
		return;
	}
	size_t i = 0;
	for (; i < seqlist->size; ++i)
	{
		if (seqlist->data[i] == value)
			return i;
	}
	return -1;
}

void SeqListRemove(SeqList *seqlist, SeqListType to_remove)//删除顺序表中to_remove的值
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t pos = SeqListFindIndex(seqlist, to_remove);
	if (pos == (size_t)-1)
	{
		return;//没找到
	}
	SeqListErase(seqlist, pos);
	return;
}

void SeqListRemoveAll(SeqList *seqlist, SeqListType to_remove)//删除顺序表中全部得to_remove的值
{
	if (seqlist == NULL)
	{
		return;
	}
	while (1)
	{
		size_t pos = SeqListFindIndex(seqlist, to_remove);
		if (pos == (size_t)-1)
		{
			break;
		}
		SeqListErase(seqlist, pos);
	}
}

//交换函数
void Swap(SeqListType *a, SeqListType *b)
{
	SeqListType tmp = *a;
	*a = *b;
	*b = tmp;
}

void SeqListBubbleSort(SeqList *seqlist)//冒泡排序
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t count = 0;//count 表示冒泡次数
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;//当前位置
		for (; cur < seqlist->size - 1 - count; ++cur)
		{
			if (seqlist->data[cur]>seqlist->data[cur + 1])
			{
				Swap(&seqlist->data[cur], &seqlist->data[cur + 1]);
			}
		}
	}
}

void SeqListBubbleSortEx(SeqList *seqlist, Cmp cmp)
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t count = 0;//count 表示冒泡次数
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;//当前位置
		for (; cur < seqlist->size - 1 - count; ++cur)
		{
			if (!cmp(seqlist->data[cur],seqlist->data[cur+1]))
			{
				Swap(&seqlist->data[cur], &seqlist->data[cur + 1]);
			}
		}
	}
}

////////////////////////////////////////////////////////////
//以下是测试代码
////////////////////////////////////////////////////////////
//#include<stdio.h>
//#include<windows.h>

#define PRINTFUNTION printf("===================  %s  ====================\n", __FUNCTION__)  

//打印测试结果
void SeqListPrintChar(SeqList * seqlist, const char * msg)
{
	if (seqlist == NULL)
	{
		printf("非法输入\n");
		return;
	}
	printf("[%s]\n", msg);
	size_t  i = 0;
	for (; i < seqlist->size; ++i)
	{
		printf("[%c] ", seqlist->data[i]);
	}
	printf("\n");
}

//测试初始化函数
void TestInit( )
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	printf("size value = %lu\n", seqlist.size);
}

//测试尾插函数
void TestPushBack()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListPrintChar(&seqlist, "尾部插入四个元素");
}

void TestPopBack()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListPopBack(&seqlist);
	SeqListPopBack(&seqlist);

	SeqListPrintChar(&seqlist, "删除尾部两个元素");
}

void TestPushFront()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListPushFront(&seqlist, 'i');
	SeqListPushFront(&seqlist, 'j');

	SeqListPrintChar(&seqlist, "头插2个元素");

	return;
}

void TestPopFront()//测试头删
{
	PRINTFUNTION;
	SeqList seqlist; 
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListPopFront(&seqlist);
	SeqListPopFront(&seqlist);

	SeqListPrintChar(&seqlist, "头删2个元素");
}

void TestInsert()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist); 
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');

	SeqListInsert(&seqlist, 2, 'd');

	SeqListPrintChar(&seqlist, "在下标2处插入元素d");
}

void TestErase()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListErase(&seqlist, 2);
	
	SeqListPrintChar(&seqlist, "删除下标2处的元素");
}

void TestRead()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListRead(&seqlist, 2);
}

void TestAlter()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListAlter(&seqlist, 2, 'e');

	SeqListPrintChar(&seqlist, "修改下标2处的元素为e");
}

void TestFindIndex()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	printf("%d\n", SeqListFindIndex(&seqlist, 'b'));
}

int main()
{
	TestInit();
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestInsert();
	TestErase();
	TestRead();
	TestAlter();
	TestFindIndex();
	system("pause");
	return 0;
}