#include <stdlib.h>
#include <stdio.h>
#include "LinkedListNode.h"
Node* LL_CreateNode(ElementType Data);
void LL_AppendNode(Node** head, ElementType data);
void LL_InsertNode(Node* Current, ElementType data);
int LL_GetNodeCount(Node* Head);
Node* LL_GetNodeAt(Node* Head, int Location);
void LL_RemoveNode(Node** Head, Node* Remove);

Node* LL_CreateNode(ElementType newData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = newData;
	NewNode->next = NULL;

	return NewNode;
}

void LL_AppendNode(Node** head, ElementType data) {
	Node* NewNode = LL_CreateNode(data);

	if (*head == NULL) {
		*head = NewNode;
	}
	else {
		Node* Tail = (*head);
		while (Tail->next != NULL) {
			Tail = Tail->next;
		}
		Tail->next = NewNode;
	}

}

void LL_InsertNode(Node* Current, ElementType data) {
	Node* NewNode = LL_CreateNode(data);;

	NewNode->next = Current->next;
	Current->next = NewNode;
}

int LL_GetNodeCount(Node* Head) {
	int count = 0;
	while (Head->next != NULL) {
		Head = Head->next;
		count++;
	}
}

Node* LL_GetNodeAt(Node* Head, int Location) {
	Node* GetNode = Head;
	while (GetNode != NULL && (--Location >= 0))
	{
		GetNode = GetNode->next;
	}

	return GetNode;
}

void LL_RemoveNode(Node** Head, Node* Remove) {
	Node* Current = *Head;
	if (Current == Remove) {
		Current = Remove->next;
	}
	else {
		while ((Current)->next != Remove && Remove != NULL) {
			Current = Current->next;
		}

		if (Current != NULL) {
			Current->next = Remove->next;
		}
	}
}

