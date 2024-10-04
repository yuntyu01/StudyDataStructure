typedef struct Node {
	char* Data;
	struct Node* Next;
}Node;

typedef struct LinkedQueue {
	int Count;
	Node* Front;
	Node* Rear;
}LinkedQueue;