#include "LinkedListStack.h"

int main() {
	LinkedListStack* stack = NULL;

	LLS_CreateStack(&stack);

	LLS_Push(stack, "¾È³ç");
	LLS_Push(stack, "ÇÏ¼¼¿ä");

	printf("%s ", stack->Top->Data);

	printf("%s ", LLS_Pop(stack)->Data);

	printf("%s ", stack->Top->Data);
}