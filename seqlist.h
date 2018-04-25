#pragma once

#define SeqListMaxSize 1000

typedef char SeqListType;
typedef struct seqlist
{
	SeqListType data[SeqListMaxSize];
	size_t size; //��ЧԪ��
}SeqList;


void SeqListInit ( SeqList * seqlist );//��ʼ��
void SeqListPushBack(SeqList * seqlist, SeqListType value);//��˳���β������valueԪ��
void SeqListPopBack(SeqList *seqlist);//βɾ
void SeqListPushFront(SeqList *seqlist,SeqListType value);//ͷ��
void SeqListPopFront(SeqList *seqlist);//ͷɾ	
void SeqListInsert(SeqList *seqlist, size_t pos, SeqListType value);//��posλ�ò���valueԪ��
void SeqListErase(SeqList *seqlist, size_t pos);//ɾ��posλ�õ�Ԫ��
void SeqListRead(SeqList *seqlist, size_t pos);//��ȡposλ�õ�Ԫ��
void SeqListAlter(SeqList *seqlist, size_t pos, SeqListType value);//����posλ�ô���Ԫ��Ϊvalue
size_t SeqListFindIndex(SeqList *seqlist, SeqListType value);//����Ԫ��value���±�	
void SeqListRemove(SeqList *seqlist, SeqListType to_remove);//ɾ��˳�����to_remove��ֵ
void SeqListRemoveAll(SeqList *seqlist, SeqListType to_remove);//ɾ��˳�����ȫ����to_remove��ֵ
void SeqListBubbleSort(SeqList *seqlist);//ð������
//����ָ��
typedef int(*Cmp)(SeqListType a, SeqListType b);
//���a��b����ȽϹ��򣬷���1�����򷵻�0.
//������������У�a<b�ͳ�Ϊ����ȽϹ���
void SeqListBubbleSortEx(SeqList *seqlist, Cmp cmp);
