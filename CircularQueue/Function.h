#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_Enqueue(CircularQueue** Queue, ElementType data) {
	int Position = 0;

	if ((*Queue)->Rear == (*Queue)->Capacity)
	{
		Position = (*Queue)->Rear;
		(*Queue)->Rear = 0;
	}
	else {
		Position = (*Queue)->Rear;
		(*Queue)->Rear++;
	}

	(*Queue)->Nodes[Position].Data = data;
}

ElementType CQ_Dequeue(CircularQueue* Queue) {
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	else {
		Queue->Front++;
	}

	return Queue->Nodes[Position].Data;

}