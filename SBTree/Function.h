#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

SBTNode* SBT_Create(ElementType NewData) {
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	
	NewNode->data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	
	return NewNode;
}

void S