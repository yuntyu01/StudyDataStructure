#include "Fuction.h"

int main() {
	LinkedQueue* queue = NULL;
	LQ_CreateQueue(&queue);

	LQ_Enqueue(&queue, "�ȳ�");
	LQ_Enqueue(&queue, "�ϼ���");

	printf("%s ", LQ_Dequeue(queue)->Data);
	printf("%s ", LQ_Dequeue(queue)->Data);
}