typedef int KeyType;
typedef int ValueType;

typedef struct tagNode {
	KeyType Key;
	ValueType Value;
}Node;

typedef struct tagHashTable {
	Node* Table;
	int TableSize;
}HashTable;