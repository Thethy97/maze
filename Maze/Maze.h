#pragma once
#include"Stack.h"

#define N 6


static int maze[N][N] = { 
{0,0,0,0,0,0},
{0,0,1,0,0,0},
{0,0,1,0,0,0},
{0,0,1,1,1,0},
{0,0,1,0,1,1},
{0,0,1,0,0,0},
};

void MazePrint();

int CheckAccess(Pos next);//查看是否越界
//int GetMazePath(Pos entry, Pos exit);
//int MazeGetShortPath(Pos entry, Pos exit);
void TestMaze();
