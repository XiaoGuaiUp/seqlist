#pragma once

#define SeqListMaxSize 1000

typedef char SeqListType;
typedef struct seqlist
{
	SeqListType data[SeqListMaxSize];
	size_t size; //有效元素
}SeqList;


void SeqListInit ( SeqList * seqlist );//初始化
void SeqListPushBack(SeqList * seqlist, SeqListType value);//往顺序表尾部插入value元素
void SeqListPopBack(SeqList *seqlist);//尾删
void SeqListPushFront(SeqList *seqlist,SeqListType value);//头插
void SeqListPopFront(SeqList *seqlist);//头删	
void SeqListInsert(SeqList *seqlist, size_t pos, SeqListType value);//在pos位置插入value元素
void SeqListErase(SeqList *seqlist, size_t pos);//删除pos位置的元素
void SeqListRead(SeqList *seqlist, size_t pos);//读取pos位置的元素
void SeqListAlter(SeqList *seqlist, size_t pos, SeqListType value);//更改pos位置处的元素为value
size_t SeqListFindIndex(SeqList *seqlist, SeqListType value);//查找元素value的下标	
void SeqListRemove(SeqList *seqlist, SeqListType to_remove);//删除顺序表中to_remove的值
void SeqListRemoveAll(SeqList *seqlist, SeqListType to_remove);//删除顺序表中全部得to_remove的值
void SeqListBubbleSort(SeqList *seqlist);//冒泡排序
//函数指针
typedef int(*Cmp)(SeqListType a, SeqListType b);
//如果a和b满足比较规则，返回1，否则返回0.
//如果是升序排列，a<b就称为满足比较规则
void SeqListBubbleSortEx(SeqList *seqlist, Cmp cmp);
