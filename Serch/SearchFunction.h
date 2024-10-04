#include "LinkedListFunction.h"
#include "BinarySearchNode.h"

Node* SLL_MoveToFront(Node** Head, int Target) {
	Node* Current = (*Head);
	Node* Previous = NULL;
	Node* Match = NULL;

	while (Current != NULL) {

		if (Current->next->data == Target) {	
			Previous = Current;
			Match = Current->next;
			break;
		}
		else
		{
			Current = Current->next;
		}
	}
	Previous->next = Match->next;
	Match->next = (*Head);
	(*Head) = Match;
	
	return Match;
}

Node* SLL_Traspose(Node** Head, int Target) {
	Node* Current = (*Head);
	Node* PPrevious = NULL;
	Node* Previous = NULL;
	Node* Match = NULL;

	while (Current != NULL) {

		if (Current->next->data == Target) {
			Previous = Current;
			Match = Current->next;
			break;
		}
		else
		{
			PPrevious = Current;
			Current = Current->next;
		}
	}
	Previous->next = Match->next;
	printf("\n%d\n", Previous->data);
	printf("\n%d\n", Match->data);
	Match->next = Previous;
	PPrevious->next = Match;

	return Match;
}

Point* BinarySearch(Point PointList[], int size, double Target) {
	int Left, Right, Mid;

	Left = 0;
	Right = size - 1;
	while (Left <= Right) {
		Mid = (Left + Right) / 2;
		if (Target == PointList[Mid].point) return &(PointList[Mid]);
		else if (Target > PointList[Mid].point) Left = Mid + 1;
		else Right = Mid - 1;
	}

	return NULL;
}

int ComparePoint(const void* _elem1, const void* _elem2) {
	Point* elem1 = (Point*)_elem1;
	Point* elem2 = (Point*)_elem2;

	if (elem1->point > elem2->point)
		return 1;
	else if (elem1->point < elem2->point)
		return -1;
	else
		return 0;
}

