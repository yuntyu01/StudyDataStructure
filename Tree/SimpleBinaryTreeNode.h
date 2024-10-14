
typedef char ElementType;

typedef struct tagSBTNode {
	struct tagSBTNode* left;
	struct tagSBTNode* right;

	ElementType Data;
}SBTNode;