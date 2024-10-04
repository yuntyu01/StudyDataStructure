#include "Function.h"
void printStack(ArrayStack* Stack);

int main() {
	ArrayStack* Stack = NULL;
	
	AS_Created(&Stack, 5);

	AS_Push(Stack, 1);
	AS_Push(Stack, 2);
	AS_Push(Stack, 3);
	AS_Push(Stack, 4);

	printStack(Stack);
	printf("\n\n");

	printf("%d ", AS_Pop(Stack));
	printf("%d ", AS_Pop(Stack));
	printf("%d ", AS_Pop(Stack));
	printf("%d ", AS_Pop(Stack));

}

void printStack(ArrayStack* Stack) {
	int top = 0;
	while (Stack->Top >= top) {
		printf("%d ", Stack->Node[top].data);
		top++;
	}
}