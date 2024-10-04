#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
int main() {

	int DataSet[] = { 5, 3, 4, 1, 2, 6, 5, 6 };
	int Lenght = sizeof(DataSet) / sizeof(DataSet[0]);
	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");
	QuickSort(DataSet, 0, Lenght - 1);
	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}


	//InsertionSort
	/*int DataSet[] = { 5, 3, 4, 1, 2 };
	int Lenght = sizeof(DataSet) / sizeof(DataSet[0]);
	printf("\nInsertionSort\n");

	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");
	InsertionSort(DataSet, Lenght);
	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}*/





	//BubbleSort
	/*int DataSet[] = { 5, 3, 4, 1, 2 };
	int Lenght = sizeof(DataSet) / sizeof(DataSet[0]);

	printf("\nBubbleSort\n");
	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");
	BubbleSort(DataSet, Lenght);

	for (int i = 0; i < Lenght; i++) {
		printf("%d ", DataSet[i]);
	}*/

}