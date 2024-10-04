#include "LinkedListFuntion.h"

int main() {
	Node* list = LL_CreateNode(1);

	LL_AppendNode(&list, 2);
	LL_AppendNode(&list, 3);
	LL_AppendNode(&list, 4);
	LL_AppendNode(&list, 5);

	Node* temp = list;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	printf("\n\nLL_GetNodeAt\n");
	temp = list;
	Node* aNode = LL_GetNodeAt(temp, 2);
	printf("aNode = %d\n", aNode->data);


	printf("\n\nLL_RemoveNode\n");
	LL_RemoveNode(&list, aNode);
	Node* temp2 = list;
	while (temp2 != NULL) {
		printf("%d\n", temp2->data);
		temp2 = temp2->next;
	}

}
