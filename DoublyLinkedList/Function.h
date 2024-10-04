#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

Node* DLL_Created(ElementType data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	return NewNode;
}

void DLL_AppendNode(Node** Head, ElementType data) {
	Node* NewNode = DLL_Created(data);

	Node* Tail = (*Head);
	if (Tail == NULL) {
		Tail = NewNode;
	}
	else {
		while (Tail->next != NULL) {
			Tail = Tail->next;
		}
		NewNode->prev = Tail;
		Tail->next = NewNode;
	}
}

Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;
	while (Current->next != NULL && (--Location >= 0)) {
		Current = Current->next;
	}
	return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->next;
		(*Head)->prev = NULL;
		Remove->next = NULL;
		Remove->prev = NULL;
	}else {
		Node* Temp = Remove;
		if (Remove->next != NULL) {
			Remove->next->prev = Temp->prev;
		}
		if (Remove->prev != NULL) {
			Remove->prev->next = Temp->next;
		}

		Remove->next = NULL;
		Remove->prev = NULL;
		
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->next = Current->next;
	NewNode->prev = Current;
	if (Current->next != NULL) {
		Current->next->prev = NewNode;
		Current->next = NewNode;
	}
}
