typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
}Node;

typedef struct tagArrayStack {
	int Capacity;
	int Top;
	Node* Nodes;
}ArrayStack;
