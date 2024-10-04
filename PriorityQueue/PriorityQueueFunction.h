#include <stdio.h>
#include <stdlib.h>
#include<String.h>
#include "Node.h"
PriorityQueue* PQ_Create(int Intitalsize);
void PQ_Destroy(PriorityQueue* PQ);
void PQ_Enqueue(PriorityQueue* PQ, PQNode* NewNode);
void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2);
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
int PQ_GetParent(int Index);
int PQ_GetLeftChild(int Index);
int PQ_IsEmpty(PriorityQueue* PQ);
PriorityQueue* PQ_Create(int Intitalsize) {
	PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	
	PQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * Intitalsize);
	PQ->Capacity = Intitalsize;
	PQ->UsedSize = 0;

	return PQ;
}

void PQ_Destroy(PriorityQueue* PQ) {
	free(PQ->Nodes);
	free(PQ);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode) {
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent(CurrentPosition);

	if (PQ->UsedSize == PQ->Capacity) {

		if (PQ->Capacity == 0)
			PQ->Capacity = 1;

		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}
	PQ->Nodes[CurrentPosition] = NewNode;

	while (CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority) {
		PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent(CurrentPosition);
	}
	PQ->UsedSize++;
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2) {
	int CopySize = sizeof(PQNode);
	PQNode* Temp = (PQNode*)malloc(CopySize);

	memcpy(Temp, &PQ->Nodes[Index1], CopySize);
	memcpy(&PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize);
	memcpy(&PQ->Nodes[Index2], Temp, CopySize);

	free(Temp);
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root) {
	int Parent = 0;
	int Left = 0;
	int Right = 0;

	memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
	memset(&PQ->Nodes[0], 0, sizeof(PQNode));

	PQ->UsedSize--;
	PQ_SwapNodes(PQ, 0, PQ->UsedSize);

	Left = PQ_GetLeftChild(0);
	Right = Left + 1;

	while (1) {
		int SelectChild = 0;
		if (Left >= PQ->UsedSize)
			break;

		if (Right >= PQ->UsedSize)
			SelectChild = Left;
		else {
			if (PQ->Nodes[Left].Priority > PQ->Nodes[Right].Priority)
				SelectChild = Right;
			else
			{
				SelectChild = Left;
			}
		}
		if (PQ->Nodes[SelectChild].Priority < PQ->Nodes[Parent].Priority)
		{
			PQ_SwapNodes(PQ, SelectChild, Parent);
			Parent = SelectChild;
		}
		else
			break;
	
		Left = PQ_GetLeftChild(Parent);
		Right = Left + 1;
	
	}
	
	if (PQ->UsedSize < PQ->Capacity / 2) {
		PQ->Capacity /= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}
}

int PQ_GetParent(int Index) {
	return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index) {
	return (2 * Index) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ) {
	return (PQ->UsedSize == 0);
}