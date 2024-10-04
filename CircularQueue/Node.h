typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct CircularQueue {
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
}CircularQueue;