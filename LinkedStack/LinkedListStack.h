#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListStackNode.h"

void LLS_CreateStack(LinkedListStack** stack) {
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->List = NULL;
	(*stack)->Top = NULL;
}

Node* LLS_CreateNode(char* NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData);

	NewNode->Next = NULL;

	return NewNode;
}

void LLS_Push(LinkedListStack* stack, char* data) {
	Node* NewNode = LLS_CreateNode(data);
	if (stack->List == NULL) {
		stack->List = NewNode;
		stack->Top = NewNode;
	}
	else {
		stack->Top->Next = NewNode;
		stack->Top = NewNode;
	}
}

Node* LLS_Pop(LinkedListStack* stack) {
	Node* TopNode = stack->Top;
	if (TopNode == stack->List) {
		stack->Top = NULL;
		stack->List = NULL;
	}
	else {
		Node* CurrentTop = stack->List;
		while (CurrentTop->Next != stack->Top && CurrentTop->Next != NULL) {
			CurrentTop = CurrentTop->Next;
		}

		stack->Top = CurrentTop;
		CurrentTop->Next = NULL;
	}

	return TopNode;
}


#pragma once
