#include "LinkedListStack.h"

int main() {
	LinkedListStack* stack = NULL;

	LLS_CreateStack(&stack);

	LLS_Push(stack, "�ȳ�");
	LLS_Push(stack, "�ϼ���");

	printf("%s ", stack->Top->Data);

	printf("%s ", LLS_Pop(stack)->Data);

	printf("%s ", stack->Top->Data);
}