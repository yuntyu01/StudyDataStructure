#define _CRT_SECURE_NO_WARNINGS
#define MAX_BUFFER 1024
#define INIT_VALUE -1

#define START 'S'
#define GOAL 'G'
#define WAY ' '
#define WALL '#'
#define MARKED '+'

enum DIRECTION {NORTH, SOUTH, EAST, WEST};
enum RESULT {FAIL, SUCCEED};

typedef struct tagPosition {
	int X;
	int Y;
}Position;

typedef struct tagMazeInfo {
	int ColumnSize;
	int RowSize;

	char** Data;
}MazeInfo;
