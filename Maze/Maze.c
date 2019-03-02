//#include"Maze.h"
//
//void MazePrint()
//{
//	size_t i = 0;
//	size_t j = 0;
//	for (i = 0; i < N; ++i)
//	{
//		for (j = 0; j < N; ++j)
//		{
//			printf("%d ", maze[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//int CheckAccess(Pos next)
//{
//	if (next._col >= 0 && next._row >= 0
//		&& next._col <= N && next._row <= N 
//		&& maze[next._col][next._row] == 1)
//	{
//			return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int GetMazePath(Pos entry, Pos exit)
//{
//	Pos cur = entry;
//
//	Stack path;
//	StackInit(&path);
//	StackPush(&path, entry);
//
//	while (StackEmpty(&path))
//	{
//		cur = StackTop(&path);
//		maze[cur._row][cur._col] = 2;//����ϴ��߹���λ��
//		if ((cur._col = exit._col) && (cur._row == exit._row))
//			return 1;
//		
//		//��
//		Pos next = cur;
//		cur._row -= 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//��
//		next = cur;
//		cur._row += 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//��
//		next = cur;
//		cur._col -= 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//��
//		next = cur;
//		cur._col += 1;
//		if (CheckAccess(next))
//		{
//			StackPush(&path, next);
//			continue;
//		}
//		//����
//		StackPop(&path);
//	}
//	return 0;
//}
//void TestMaze()
//{
//	Pos entry;
//	Pos exit;
//	int ret;
//	entry._row = 5;//��
//	entry._col = 2;
//
//
//	exit._row = 4;
//	exit._col = 5;
//	MazePrint();
//	ret = GetMazePath(entry, exit);
//	if (ret == 1)
//		printf("�г���\n");
//	if (ret == 0)
//		printf("û��\n");
//	MazePrint();
//}
//////////////////////////////////////////////////////
#include "Maze.h"

int CheckAccess(Pos cur, Pos next)
{
	if ((next._row >= 0 && next._row < N && next._col >= 0 && next._col < N)
		&& (maze[next._row][next._col] == 1 || maze[next._row][next._col] > maze[cur._row][cur._col] + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Stack minpath;
int pathsize = 0;

int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	maze[entry._row][entry._col] = 2;

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;
	
		if (cur._col == 5)
		{
			if(pathsize == 0 
				|| StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}

		}

		// ̽����һ������ȥ��λ��

		// ��
		next = cur;
		next._row -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col]+1;
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col]+1;
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col]+1;
			StackPush(&path, next);
			continue;
		}

		// ��
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col]+1;
			StackPush(&path, next);
			continue;
		}

		// ����
		StackPop(&path);
	}

	return 0;
}

void PrintMaze()
{
	size_t  i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

void TestMaze()
{
	Pos entry, exit;
	entry._row = 5;
	entry._col = 2;

	exit._row = 4;
	exit._col = 5;

	PrintMaze();

	printf("�Ƿ��г���?:%d\n", GetMazePath(entry, exit));
	printf("���·��:%d\n", pathsize);

	PrintMaze();
}