#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "MyLinkedListFunction.h"


int main()
{
	Node* List = NULL;
	Node* MyNode = NULL;

	SLL_AppendNode(&List, SLL_CreateNode(117));
	SLL_AppendNode(&List, SLL_CreateNode(119));

	MyNode = SLL_GetNodeAt(List, 1);
	printf("%d\n", MyNode->Data);

	SLL_DestroyNode(List);
	SLL_DestroyNode(MyNode);
}

