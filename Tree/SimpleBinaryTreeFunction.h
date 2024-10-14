#include <stdio.h>
#include <stdlib.h>
#include "SimpleBinaryTreeNode.h"

SBTNode* SBT_CreateNode(ElementType NewData) {
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void SBT_DestoryNode(SBTNode* Node) {
	free(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node) {
	if (Node == NULL) {
		return;
	}

	printf(" %C", Node->Data);

	SBT_PreorderPrintTree(Node->left);
	SBT_PreorderPrintTree(Node->right);

}

void SBT_InorderPrintTree(SBTNode* Node) {
	if (Node == NULL)
		return;

	SBT_InorderPrintTree(Node->left);

	printf(" %c", Node->Data);

	SBT_InorderPrintTree(Node->right);

}