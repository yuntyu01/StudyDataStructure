#include<stdlib.h>
#include<stdio.h>
#include "Node.h"

LCRSNode* LCRS_CreateNode(ElementType data) {

	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->data = data;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
	if (Parent->Left == NULL) {
		Parent->Left = Child;
	}
	else {
		LCRSNode* temp = Parent->Left;
		while (temp->Right != NULL) {
			temp = temp->Right;
		}
		temp->Right = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth) {
	int i = 0;
	for (i = 0; i < Depth - 1; i++) {
		printf("   ");
	}

	if (Depth > 0) {
		printf("+--");
	}

	printf("%c\n", Node->data);

	if (Node->Left != NULL)
		LCRS_PrintTree(Node->Left, Depth + 1);

	if (Node->Right != NULL) {
		LCRS_PrintTree(Node->Right, Depth);
	}
}