#include "Function.h"

int main() {
	LCRSNode* A = LCRS_CreateNode('A');
	LCRSNode* B = LCRS_CreateNode('B');
	LCRSNode* C = LCRS_CreateNode('C');
	LCRSNode* D = LCRS_CreateNode('D');
	LCRSNode* E = LCRS_CreateNode('E');
	LCRSNode* F = LCRS_CreateNode('F');
	LCRSNode* G = LCRS_CreateNode('G');
	LCRSNode* H = LCRS_CreateNode('H');

	LCRS_AddChildNode(A, B);
		LCRS_AddChildNode(A, C);
			LCRS_AddChildNode(C, E);
			LCRS_AddChildNode(C, F);
				LCRS_AddChildNode(F, G);
				LCRS_AddChildNode(F, H);
		LCRS_AddChildNode(A, D);
	
	
	LCRS_PrintTree(A, 0);
}