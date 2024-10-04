#include "Function.h"

int main() {

	CircularQueue* queue = NULL;
	CQ_CreateQueue(&queue, 10);

	CQ_Enqueue(&queue, 1);
	CQ_Enqueue(&queue, 2);
	CQ_Enqueue(&queue, 3);
	CQ_Enqueue(&queue, 4);

	printf("%d ", CQ_Dequeue(queue));
	printf("%d ", CQ_Dequeue(queue));
	printf("%d ", CQ_Dequeue(queue));
	printf("%d ", CQ_Dequeue(queue));
}