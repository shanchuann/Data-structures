#include<stdio.h>
#include<string.h>
#include"GenListStack.h"
#include "Maze.h"
bool Pass(MazeType maze, PosType pos)
{
	if (pos.row < 0 || pos.row >= ROWSIZE || pos.col < 0 || pos.col >= COLSIZE)
	{
		return false;
	}
	if (maze[pos.row][pos.col] == PASS)
	{
		return true;
	}
	return false;
}
void FootPrint(MazeType maze, PosType pos)
{
	maze[pos.row][pos.col] = FOOT;
}
void MarkPrint(MazeType maze, PosType pos)
{
	maze[pos.row][pos.col] = MARK;
}
PosType NextPos(PosType pos, int di)
{
	PosType nextpos = pos;
	switch (di)
	{
	case 1:
		nextpos.col++;
		break;
	case 2:
		nextpos.row++;
		break;
	case 3:
		nextpos.col--;
		break;
	case 4:
		nextpos.row--;
		break;
	}
	return nextpos;
}
void InitMaze(MazeType maze)
{
	MazeType tmp = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,1},
		{1,0,1,1,1,1,0,1,1,1},
		{1,0,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1},
	};
	memmove(maze, tmp, sizeof(tmp));
}
void PrintMaze(MazeType maze)
{
	printf("\n_______________________________\n");
	for (int i = 0; i < ROWSIZE; ++i)
	{
		for (int j = 0; j < COLSIZE; ++j)
		{
			printf("%3d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n________________________________\n");
}
bool PathMaze(MazeType maze, const PosType start, const PosType end)
{
	GenListStack mys;
	InitGenListStack(&mys, sizeof(SElemType));
	SElemType e = {};
	PosType curpos = start;
	int step = 1;
	do
	{
		if (Pass(maze, curpos))
		{
			FootPrint(maze, curpos);
			if (curpos.row == end.row && curpos.col == end.col)
			{
				return true;
			}
			e.seat = curpos;   e.di = 1; e.ord = step++;
			Push(&mys, &e);
			curpos = NextPos(curpos, 1);
		}
		else
		{
			if (!StackEmpty(&mys))
			{
				Pop(&mys, &e);
				while (e.di == 4 && !StackEmpty(&mys))
				{
					MarkPrint(maze, e.seat);
					Pop(&mys, &e);
				}
				if (e.di < 4)
				{
					e.di += 1;
					Push(&mys, &e);
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
	} while (!StackEmpty(&mys));
	DestroyGenListStack(&mys);
	return true;
}