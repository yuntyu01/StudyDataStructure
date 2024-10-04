#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void AS_Created(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Node = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_Push(ArrayStack* Stack, ElementType data) {
	Stack->Top ++;
	Stack->Node[Stack->Top].data = data;
}

ElementType AS_Pop(ArrayStack* Stack) {
	int Position = Stack->Top--;
	return Stack->Node[Position].data;

}