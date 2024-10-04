typedef int ElementType;

typedef struct Node {
	ElementType data;
}Node;

typedef struct ArrayStack {
	int Capacity;
	int Top;
	Node* Node;
}ArrayStack;

