typedef int PriorityType;

typedef struct PagePQNode {
	PriorityType Priority;
	void* Data;
}PQNode;

typedef struct tagPriorityQueue {
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
}PriorityQueue;
