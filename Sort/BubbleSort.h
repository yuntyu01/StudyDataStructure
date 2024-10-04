#include <stdio.h>

void BubbleSort(int DataSet[], int Lenght) {
	for (int i = 0; i < Lenght - 1; i++) {
		for (int j = 0; j < Lenght - (i+1); j++) {
			if (DataSet[j] > DataSet[j + 1]) {
				int temp = DataSet[j];
				DataSet[j] = DataSet[j + 1];
				DataSet[j + 1] = temp;
			}
		}
	}
}