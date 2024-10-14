#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode {
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	ElementType Data;
}LCRSNode;

