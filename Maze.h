#ifndef MAZE_HPP
#define MAZE_HPP

#define ROWSIZE 10
#define COLSIZE 10
#define PASS    0
#define FOOT    8
#define MARK    4 

typedef int MazeType[ROWSIZE][COLSIZE];
typedef struct
{
	int row;
	int col;
}PosType;
typedef struct
{
	PosType seat;
	int di; // 1 ; 2 ; 3; 4;
	int ord;// 1 2 3 4 
}SElemType;

extern void InitMaze(MazeType maze);
extern void PrintMaze(MazeType maze);
extern bool PathMaze(MazeType maze, const PosType start, const PosType end);


#endif 
