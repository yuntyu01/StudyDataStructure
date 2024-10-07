typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode {
	KeyType Key;
	ValueType Value;

	struct tagNode* Next;
}Node;

typedef  Node* List;
typedef struct tagHashTable {
	int TableSize;
	List* Table;
}HashTable;