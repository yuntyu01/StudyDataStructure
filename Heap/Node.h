typedef int ElementType;

typedef struct tageHeapNode {
	ElementType Data;
}HeapNode;

typedef struct tagHeap {
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;