#include <stdio.h>
#include <stdlib.h>

void Merge(int DataSet[], int StartIndex, int MiddleIndex, int EndIndex);

void MergeSort(int DataSet[], int StartIndex, int EndIndex) {
    int MiddleIndex;

    if (EndIndex - StartIndex < 1)
        return;

    MiddleIndex = (StartIndex + EndIndex) / 2;

    MergeSort(DataSet, StartIndex, MiddleIndex);
    MergeSort(DataSet, MiddleIndex + 1, EndIndex);

    Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
}

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

int main() {
    int DataSet[] = { 10, 3, 5, 9, 2, 8, 4, 7, 6, 1 };
    int Length = sizeof(DataSet) / sizeof(DataSet[0]);

    MergeSort(DataSet, 0, Length - 1);

    for (int i = 0; i < Length; i++) {
        printf("%d ", DataSet[i]);
    }

    return 0;
}
