#include "Funtion.h"
void printList(Node* list);

int main() {
	Node* list = CLL_Created(1);
	printList(list);

	CLL_Append(&list, 2);
	CLL_Append(&list, 3);
	CLL_Append(&list, 4);
	printList(list);


	CLL_RemoveNode(&list, list);
	printList(list);
}

void printList(Node* list) {
	Node* Current = list;

	do {
		printf("%d ", Current->data);
		Current = Current->next;
	} while (Current != list);

	printf("\n");
}