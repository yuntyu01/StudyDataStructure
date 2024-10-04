typedef int ElementType;

typedef struct Node {
	ElementType data;
	struct Node* next;
	struct Node* prev;

}Node;