#include<stdlib.h>
#include<stdio.h>
#include "Node.h"

Node* CLL_Created(ElementType data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = data;
	NewNode->next = NewNode;
	NewNode->prev = NewNode;

	return NewNode;
}

void CLL_Append(Node** Head, ElementType data) {
	Node* NewNode = CLL_Created(data);

	if (*Head == NULL) {
		*Head = NewNode;
		(*Head)->next = *Head;
		(*Head)->prev = *Head;
	}
	else {
		Node* Tail = (*Head)->prev;
		Tail->next = NewNode;
		NewNode->prev = Tail;

		NewNode->next = *Head;
		(*Head)->prev = NewNode;
	}
}
	
	void CLL_RemoveNode(Node** Head, Node* Remove) {
		if ((*Head) == Remove) {
			(*Head)->next->prev = Remove->prev;
			(*Head)->prev->next = Remove->next;

			*Head = Remove->next;

			Remove->prev = NULL;
			Remove->next = NULL;

			}
		else {
			Remove->next->prev = Remove->prev;
			Remove->prev->next = Remove->next;

			Remove->prev = NULL;
			Remove->next = NULL;

		}
}
	
