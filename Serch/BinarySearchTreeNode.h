#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode {
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;

	ElementType Data;
}BSTNode;