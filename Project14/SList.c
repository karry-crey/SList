#include"SList.h"
void SLTPrint(SLTNode* phead) {
	SLTNode* pcur = phead;
	while (pcur) {
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//create new node
SLTNode* SLTbuyNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc failed");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}



//push back
void SLTPushBack(SLTNode** pphead, SLTDataType x) {

	SLTNode* newnode = SLTbuyNode(x);
	//list is NULL
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	//list is not NULL
	else {
		SLTNode* ptail = *pphead;
		while (ptail->next) {
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}

}

//push front
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
		newnode->next = *pphead;
		*pphead = newnode;
}
//pop back
void SLTPopBack(SLTNode** pphead) {
	assert(pphead && *pphead);
	//only one head
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//find pre and ptail
		SLTNode* pre = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next) {
			pre = ptail;
			ptail = ptail->next;
		}
		pre->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

void SLTPopFront(SLTNode** pphead) {
	assert(pphead && *pphead);
	//if ((*pphead)->next == NULL) {
	//	free(*pphead);
	//	*pphead = NULL;
	//}
	//else {
		//SLTNode* pre = *pphead;
		//*pphead = (*pphead)->next;
		//free(pre);
		//pre = NULL;
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	//}
}
	
