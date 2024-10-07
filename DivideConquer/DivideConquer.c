//#include "MergeSort.h"
//#include "FastExponentaiton.h"
#include "FibonacciDn.h"

int main() {
	//int DataSet[] = { 334, 6, 4, 2, 3, 1, 5, 117, 12, 34 };
	//int Length = sizeof DataSet / sizeof DataSet[0];
	//
	//MergeSort(DataSet, 0, Length - 1);

	//for (int i = 0; i < Length; i++) {
	//	printf("%d ", DataSet[i]);
	//}

	//printf("\n");

	//int Base = 2;
	//int Exponent = 30;
	//printf("%d^%d = %lu\n", Base, Exponent, Power(Base, Exponent));

	printf("\n");

	int N = 46;
	ULONG Result = Fibonacci(N);

	printf("Fabonacci(%d) = %lu\n", N, Result);
}