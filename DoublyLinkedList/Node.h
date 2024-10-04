typedef int ElementType;

typedef struct DoubleListNode{
	ElementType data;
	struct DoubleListNode* next;
	struct DoubleListNode* prev;

}Node;