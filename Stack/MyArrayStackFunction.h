#include "MyArrayNode.h"
#include <stdio.h>
#include <stdlib.h>

void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;

}

void AS_Push(ArrayStack* Stack, ElementType Data) {
	if (Stack->Top + 1 == Stack->Capacity) {
		printf("꽉 찼습니다");
		return -1;
	}
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;

}

ElementType AS_Pop(ArrayStack* Stack) {
	if (Stack->Top -1 == -1) {
		printf("더는 뺼 게 없습니다");
		return;
	}
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

void AS_DestoryStack(ArrayStack* Stack) {
	free(Stack->Nodes);

	free(Stack);
}
