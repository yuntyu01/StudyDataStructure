#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG Fibonacci(int N){
	ULONG result;
	ULONG* FabonacciTable;

	if (N == 0 || N == 1)
		return N;

	FabonacciTable = (ULONG*)malloc(sizeof(ULONG) * N);

	FabonacciTable[0] = 0;
	FabonacciTable[1] = 1;
	for (int i = 2; i <= N; i++) {
		FabonacciTable[i] = FabonacciTable[i - 1] + FabonacciTable[i - 2];
	}

	result = FabonacciTable[N];

	return result;
}