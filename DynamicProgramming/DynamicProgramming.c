//#include "FibonacciDP.h"
#include "LCS.h"

int main() {
	//printf("%lu", Fibonacci(46));

	char* X = "GOOD MORNING.";
	char* Y = "GUTEN MORGEN.";
	char* Result;

	int LEN_X = strlen(X);
	int LEN_Y = strlen(Y);

	int i = 0;
	int Length = 0;

	LCSTable Table;

	Table.Data = (int**)malloc(sizeof(int*) * (LEN_X + 1));

	for (i = 0; i < LEN_X + 1; i++) {
		Table.Data[i] = (int*)malloc(sizeof(int) * (LEN_Y + 1));

		memset(Table.Data[i], 0, sizeof(int) * (LEN_Y + 1));
	}

	Length = LCS(X, Y, LEN_X, LEN_Y, &Table);

	LCS_PrintTable(&Table, X, Y, LEN_X, LEN_Y);

	size_t TableSize = sizeof(Table.Data[LEN_X][LEN_Y] + 1);
	Result = (char*)malloc(Length + 1);
	memset(Result, 0, TableSize);

	LCS_TraceBack(X, Y, LEN_X, LEN_Y, &Table, Result);

	printf("\n");
	printf("LCS:\"%s\" (LENGTH:%d)\n", Result, Length);

	return 0;
}