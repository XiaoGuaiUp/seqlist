#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include<stdio.h>
#include<windows.h>
#include "seqlist.h"

//˳����ʼ��
void SeqListInit(SeqList * seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	seqlist->size = 0;
}

//��˳���β������Ԫ��value
void SeqListPushBack(SeqList * seqlist, SeqListType value)
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{
		//˳�������
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
	{//˳����ǿ�
		return;
	}
	--seqlist->size;
	return;
}

void SeqListPushFront(SeqList *seqlist, SeqListType value)//ͷ��
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{//����
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

void SeqListPopFront(SeqList *seqlist)//ͷɾ
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{//��
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

void SeqListInsert(SeqList *seqlist, size_t pos, SeqListType value)//��posλ�ò���valueԪ��
{
	if (seqlist == NULL)
	{
		return;
	}
	if (pos >= seqlist->size)
	{//Խ����
		return;
	}
	if (seqlist->size >= SeqListMaxSize)
	{//����
		return;
	}
	if (pos == 0)
	{//���pos=0ʱ�������--iΪ-1ʱ��size_t���޷��ų����ͣ�����Ϊһ�����������ֵ
		//��תΪͷ�庯��
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

void SeqListErase(SeqList *seqlist, size_t pos)//ɾ��posλ�õ�Ԫ��
{
	if (seqlist == NULL)
	{
		return;
	}
	if (seqlist->size == 0)
	{//��
		return;
	}
	if (pos >= seqlist->size)
	{//posֵԽ��
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

void SeqListRead(SeqList *seqlist, size_t pos)//��ȡposλ�õ�Ԫ��
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

void SeqListAlter(SeqList *seqlist, size_t pos, SeqListType value)//����posλ�ô���Ԫ��Ϊvalue
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

size_t SeqListFindIndex(SeqList*seqlist, SeqListType value)//����Ԫ��value���±�
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

void SeqListRemove(SeqList *seqlist, SeqListType to_remove)//ɾ��˳�����to_remove��ֵ
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t pos = SeqListFindIndex(seqlist, to_remove);
	if (pos == (size_t)-1)
	{
		return;//û�ҵ�
	}
	SeqListErase(seqlist, pos);
	return;
}

void SeqListRemoveAll(SeqList *seqlist, SeqListType to_remove)//ɾ��˳�����ȫ����to_remove��ֵ
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

//��������
void Swap(SeqListType *a, SeqListType *b)
{
	SeqListType tmp = *a;
	*a = *b;
	*b = tmp;
}

void SeqListBubbleSort(SeqList *seqlist)//ð������
{
	if (seqlist == NULL)
	{
		return;
	}
	size_t count = 0;//count ��ʾð�ݴ���
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;//��ǰλ��
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
	size_t count = 0;//count ��ʾð�ݴ���
	for (; count < seqlist->size; ++count)
	{
		size_t cur = 0;//��ǰλ��
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
//�����ǲ��Դ���
////////////////////////////////////////////////////////////
//#include<stdio.h>
//#include<windows.h>

#define PRINTFUNTION printf("===================  %s  ====================\n", __FUNCTION__)  

//��ӡ���Խ��
void SeqListPrintChar(SeqList * seqlist, const char * msg)
{
	if (seqlist == NULL)
	{
		printf("�Ƿ�����\n");
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

//���Գ�ʼ������
void TestInit( )
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	printf("size value = %lu\n", seqlist.size);
}

//����β�庯��
void TestPushBack()
{
	PRINTFUNTION;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist, 'a');
	SeqListPushBack(&seqlist, 'b');
	SeqListPushBack(&seqlist, 'c');
	SeqListPushBack(&seqlist, 'd');

	SeqListPrintChar(&seqlist, "β�������ĸ�Ԫ��");
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

	SeqListPrintChar(&seqlist, "ɾ��β������Ԫ��");
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

	SeqListPrintChar(&seqlist, "ͷ��2��Ԫ��");

	return;
}

void TestPopFront()//����ͷɾ
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

	SeqListPrintChar(&seqlist, "ͷɾ2��Ԫ��");
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

	SeqListPrintChar(&seqlist, "���±�2������Ԫ��d");
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
	
	SeqListPrintChar(&seqlist, "ɾ���±�2����Ԫ��");
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

	SeqListPrintChar(&seqlist, "�޸��±�2����Ԫ��Ϊe");
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