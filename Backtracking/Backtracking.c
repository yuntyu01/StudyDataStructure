#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MazeSolverFunction.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int j = 0;

	MazeInfo Maze;

	if (argc < 2) {
		printf("Usage: MazeSolver <MazeFile>\n");
		return 0;
	}
	if (GetMaze(argv[i], &Maze) == FAIL)
		return 0;

	if (Solve(&Maze) == FAIL)
		return 0;

	for (i = 0; i < Maze.RowSize; i++)
	{
		for (j = 0; j < Maze.ColumnSize; j++)
			printf("%c", Maze.Data[i][j]);
		printf("\n");
	}
	return 0;
}