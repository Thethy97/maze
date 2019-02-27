#include"Maze.h"
#include"Stack.h"
void MazePrint()
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int CheckAccess(Pos next)
{
	if (next._col >= 0 && next._row >= 0
		&& next._col <= N && next._row <= N)
	{
		if (maze[next._col][next._row] == 1)//��ͨ·
			return 1;
	}
	return 0;
}
int GetMazePath(Pos entry, Pos exit)
{
	Pos cur = entry;

	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if ((cur._col = exit._col) && (cur._row == exit._row))
			return 1;
		maze[cur._col][cur._row] = 2;//����ϴ��߹���λ��
		//��
		Pos next = cur;
		cur._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		cur._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		cur._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		cur._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);
	}
	return 0;
}
void TestMaze()
{
	Pos entry;
	entry._row = 6;//��
	entry._col = 3;

	Pos exit;
	exit._row = 5;
	exit._col = 6;
	MazePrint();
	int i = GetMazePath(entry, exit);
	printf("�Ƿ��г��ڣ�%d\n",i);
	MazePrint();
}
