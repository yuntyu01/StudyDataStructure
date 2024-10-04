#include "Funtion.h"

void printList(Node* list);

int main() {
	Node* list = DLL_Created(10);

	DLL_AppendNode(&list, 1);
	DLL_AppendNode(&list, 2);
	DLL_AppendNode(&list, 3);
	DLL_AppendNode(&list, 4);
	printList(list);
	
	Node* test = DLL_GetNodeAt(list, 3);
	DLL_RemoveNode(&list, test);
	printList(list);

	DLL_InsertAfter(list, test);
	printList(list);

}

void printList(Node* list) {
	while (list != NULL) {
		printf("\n%d", list->data);
		list = list->next;
	}

}