#include <stdio.h>
#include <stdlib.h>

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex) {
	int i;
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex + 1;
	int DestIndex = 0;

	int* Destination = (int*)malloc(sizeof(int) * (EndIndex - StartIndex + 1));

	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex) {
		if (DataSet[LeftIndex] < DataSet[RightIndex]) {
			Destination[DestIndex] = DataSet[LeftIndex];
			LeftIndex++;
		}
		else {
			Destination[DestIndex] = DataSet[RightIndex];
			RightIndex++;
		}
		DestIndex++;
	}

	while (LeftIndex <= MiddleIndex)
		Destination[DestIndex++] = DataSet[LeftIndex++];

	while (RightIndex <= EndIndex)
		Destination[DestIndex++] = DataSet[RightIndex++];

	DestIndex = 0;
	for (i = StartIndex; i <= EndIndex; i++) {
		DataSet[i] = Destination[DestIndex++];
	}

	free(Destination);
}

void MergeSort(int DataSet[], int StartIndex, int EndIndex) {
	int MiddleIndex;

	if (EndIndex - StartIndex < 1)
		return;

	MiddleIndex = (EndIndex + StartIndex) / 2;

	MergeSort(DataSet, StartIndex, MiddleIndex);
	MergeSort(DataSet, MiddleIndex + 1, EndIndex);

	Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
}

