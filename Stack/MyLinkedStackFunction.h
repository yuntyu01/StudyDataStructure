#include "MyLinkedNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LLS_CreateStack(LinkedListStack** Stack) {
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}



Node* LLS_CreateNode(char* NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;
	
	return NewNode;
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode) {
	if (Stack->List == NULL) {
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}
}

Node* LLS_Pop(LinkedListStack* Stack) {
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else {
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;
		Stack->Top->NextNode = NULL;
	}

	return TopNode;
}
void LLS_DestroyStack(LinkedListStack* Stack) {
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}

bool LLS_IsEmpty(LinkedListStack* Stack){
	return Stack->List == NULL;
}

void LLS_DestroyNode(Node* _Node) {
	free(_Node->Data);
	free(_Node);
}

