#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

void LQ_CreateQueue(LinkedQueue** queue) {
	(*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*queue)->Count = 0;
	(*queue)->Front = NULL;
	(*queue)->Rear = NULL;
}

Node* LQ_CreateNode(char* data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(data) + 1);

	strcpy(NewNode->Data, data);
	NewNode->Next = NULL;

	return NewNode;
}

void LQ_Enqueue(LinkedQueue** queue, char* data) {
	Node* NewNode = LQ_CreateNode(data);

	if ((*queue)->Front == NULL) {
		(*queue)->Front = NewNode;
	}
	else {
		(*queue)->Rear->Next = NewNode;
	}

	(*queue)->Rear = NewNode;
	(*queue)->Count++;
}

Node* LQ_Dequeue(LinkedQueue* queue) {
	Node* Front = queue->Front;
	if (queue->Front->Next == NULL) {
		queue->Front = NULL;
		queue->Rear = NULL;
	}
	else {
		queue->Front = queue->Front->Next;
	}
	queue->Count--;

	return Front;

}
