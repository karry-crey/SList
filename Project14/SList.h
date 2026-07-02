#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;
//define the structure of single list
typedef struct SListNode {
	SLTDataType data;//data to be stored
	struct SListNode* next;
}SLTNode;

//print list
void SLTPrint(SLTNode* phead);


SLTNode* SLTbuyNode(SLTDataType x);

void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);

void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);