typedef int ElementType;

typedef struct tageHeapNode {
	ElementType data;
}HeapNode;

typedef struct tagHeap {
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;