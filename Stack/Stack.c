#include <stdio.h>
#include "MyArrayStackFunction.h"

int main() {
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 1);
	AS_Push(Stack, 2);
	AS_Push(Stack, 3);
	AS_Push(Stack, 4);

	printf("%d", AS_Pop(Stack));
	printf("%d", AS_Pop(Stack));
	printf("%d", AS_Pop(Stack));
	printf("%d", AS_Pop(Stack));

}