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
SLTNode* SLTFind(SLTNode* phead,SLTDataType x) {
	SLTNode* pcur = phead;
	while (pcur) {
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//insert before 	
void SLTInsert(SLTNode** pphead,SLTNode* pos, SLTDataType x) {
	assert(pphead && pos);
	SLTNode* newnode = SLTbuyNode(x);
	//if pos points to the first node,use pushfront
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else {
		//find the previous node of pos
		SLTNode* pre = *pphead;
		while (pre->next != pos) {
			pre = pre->next;
		}
		newnode->next = pos;
		pre->next = newnode;
	}
}
//insert after
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//erase the previous node of pos
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead && pos &&*pphead);
    //if pos points to the first node
	if (*pphead == pos) {
		SLTPopFront(pphead);
	}
	else {
		SLTNode* pre = *pphead;
		while (pre->next != pos) {
			pre = pre->next;
		}
		pre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//erase the node after pos
void SLTEraseAfter(SLTNode* pos) {
	assert(pos&&pos->next);
	SLTNode* after = pos->next;
	pos->next = after->next;
	free(after);
	after = NULL;
}
void SListDestroy(SLTNode** pphead) {
	SLTNode* pcur = *pphead;
	while (pcur) {
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;

}

