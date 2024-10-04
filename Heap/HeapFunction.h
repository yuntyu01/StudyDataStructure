#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

Heap* HEAP_Create(int Capacity);
void Heap_Insert(Heap* H, ElementType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
void HEAP_SwapNodes(Heap* H, int index1, int index2);
int HEAP_GetLeftChild(int Index);
int HEAP_GetParent(int Index);
void HEAP_PrintNodes(Heap* H);

Heap* HEAP_Create(int Capacity) {
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = Capacity;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * Capacity);

	return NewHeap;
}

void HEAP_Insert(Heap* H, ElementType NewData) {
	int CurrentPosition = H->UsedSize;
	int ParentPosition = HEAP_GetParent(CurrentPosition);

	if (H->UsedSize == H->Capacity) {
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);

	}

	H->Nodes[CurrentPosition].data = NewData;

	while (CurrentPosition > 0 && H->Nodes[CurrentPosition].data < H->Nodes[ParentPosition].data) {
		HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = HEAP_GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void HEAP_DeleteMin(Heap* H, HeapNode* Root) {
	int ParenPostion = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	HEAP_SwapNodes(H, 0, H->UsedSize);

	LeftPosition = HEAP_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1) {
		int SelectedChild = 0;
		if (LeftPosition >= H->UsedSize)
			break;

		if (RightPosition >= H->UsedSize)
			SelectedChild = LeftPosition;
		else {
			if (H->Nodes[LeftPosition].data > H->Nodes[RightPosition].data)
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}

		if (H->Nodes[SelectedChild].data < H->Nodes[ParenPostion].data) {
			HEAP_SwapNodes(H, ParenPostion, SelectedChild);
			ParenPostion = SelectedChild;
		}
		else
			break;

		LeftPosition = HEAP_GetLeftChild(ParenPostion);
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2))
	{
		H->Capacity /= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

void HEAP_SwapNodes(Heap* H, int index1, int index2) {
	int CopySize = sizeof(HeapNode);
	HeapNode* Temp = (HeapNode*)malloc(CopySize);

	memcpy(Temp, &H->Nodes[index1], CopySize);
	memcpy(&H->Nodes[index1], &H->Nodes[index2], CopySize);
	memcpy(&H->Nodes[index2], Temp, CopySize);

	free(Temp);
}

int HEAP_GetLeftChild(int Index) {
	return (2 * Index) + 1;
}

int HEAP_GetParent(int Index) {
	return (int)((Index - 1) / 2);
}

void HEAP_PrintNodes(Heap* H) {
	int i = 0;
	for (i = 0; i < H->UsedSize; i++) {
		printf("%d ", H->Nodes[i].data);
	}
	printf("\n");
}