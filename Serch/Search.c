#include "SearchFunction.h"
#include "BinarySearchTreeFunction.h"
void PrintSearchResult(int SearchTarget, BSTNode* Result) {
	if (Result != NULL) {
		printf("Found : %d \n", Result->Data);
	}
	else
		printf("Not Found: %d\n", SearchTarget);
}
int main() {

    {
        BSTNode* Tree = BST_CreateNode(123);
        BSTNode* Node = NULL;

        BST_InsertNode(Tree, BST_CreateNode(22));
        BST_InsertNode(Tree, BST_CreateNode(9918));
        BST_InsertNode(Tree, BST_CreateNode(424));
        BST_InsertNode(Tree, BST_CreateNode(17));
        BST_InsertNode(Tree, BST_CreateNode(3));

        BST_InsertNode(Tree, BST_CreateNode(98));
        BST_InsertNode(Tree, BST_CreateNode(34));

        BST_InsertNode(Tree, BST_CreateNode(760));
        BST_InsertNode(Tree, BST_CreateNode(317));
        BST_InsertNode(Tree, BST_CreateNode(1));

        int SearchTarget = 17;
        Node = BST_SearchNode(Tree, SearchTarget);
        PrintSearchResult(SearchTarget, Node);

        SearchTarget = 117;
        Node = BST_SearchNode(Tree, SearchTarget);
        PrintSearchResult(SearchTarget, Node);

        BST_InorderPrintTree(Tree);
        printf("\n");

        printf("Removing 98...\n");

        Node = BST_RemoveNode(Tree, NULL, 98);
        BST_DestroyNode(Node);

        BST_InorderPrintTree(Tree);
        printf("\n");

        printf("Inserting 111...\n");

        BST_InsertNode(Tree, BST_CreateNode(111));
        BST_InorderPrintTree(Tree);
        printf("\n");

        BST_DestroyTree(Tree);

        return 0;
    }






	//BinarySerch
	//int Length = sizeof DataSet / sizeof DataSet[0];
	//Point* found = NULL;

	//qsort((void*)DataSet, Length, sizeof(Point), ComparePoint);

	//found = BinarySerch(DataSet, Length, 671.78);

	//printf("ID :%d, Point: %f \n", found->id, found->point);





	////Move To Front Method
	//Node* A = LL_CreateNode(1);
	//LL_AppendNode(&A, 2);
	//LL_AppendNode(&A, 3);
	//LL_AppendNode(&A, 4);
	//LL_AppendNode(&A, 5);
	//LL_AppendNode(&A, 6);
	//LL_AppendNode(&A, 7);
	//LL_AppendNode(&A, 8);

	//SLL_Traspose(&A, 5);
	//SLL_Traspose(&A, 5);
	//SLL_Traspose(&A, 5);

	//Node* temp = A;
	//while (temp != NULL) {
	//	printf("%d ", temp->data);
	//	temp = temp->next;
	//}
}