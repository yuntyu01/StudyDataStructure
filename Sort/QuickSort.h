#include <stdio.h>

void swap(int* A, int* B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

int Partiton(int DataSet[], int Left, int Right) {
	int first = Left;
	int Pivot = DataSet[first];

	Left++;
	while (Left <= Right) {
		while (DataSet[Left] <= Pivot && Left < Right) Left++;
		while (DataSet[Right] >= Pivot && Left <= Right) Right--;

		if (Left < Right) {
			swap(&DataSet[Left], &DataSet[Right]);
		}
		else
			break;
	}
	swap(&DataSet[first], &DataSet[Right]);

	return Right;
}

void QuickSort(int DataSet[], int Left, int Right) {
	int Index = Partiton(DataSet, Left, Right);
	
	if (Left < Right) {
		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}