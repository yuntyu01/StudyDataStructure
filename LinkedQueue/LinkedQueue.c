#include "Fuction.h"

int main() {
	LinkedQueue* queue = NULL;
	LQ_CreateQueue(&queue);

	LQ_Enqueue(&queue, "¾È³ç");
	LQ_Enqueue(&queue, "ÇÏ¼¼¿ä");

	printf("%s ", LQ_Dequeue(queue)->Data);
	printf("%s ", LQ_Dequeue(queue)->Data);
}