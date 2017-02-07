#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

#define TRUE 1 
#define FALSE 0 

const char LIVE_CELL = '*';
const char DEAD_CELL = '.';

int GetLiveCellsAround(char world[ROWS][COLS], int currentI, int currentJ)
{
	int cellCounter = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (currentI + i < 0 || currentI + i >= ROWS)
			{
				continue;
			}
			if (currentJ + j < 0 || currentJ + j >= COLS)
			{
				continue;
			}
			if (0 == j && 0 == i)
			{
				continue;
			}
			if (world[currentI + i][currentJ + j] == LIVE_CELL)
			{
				cellCounter++;
			}
		}
	}
	return cellCounter;
}

void CopyWorld(char newWorld[ROWS][COLS], char destWorld[ROWS][COLS])
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			newWorld[i][j] = destWorld[i][j];
		}
	}
}

void PrintWorld(char world[ROWS][COLS])
{
	for (size_t i = 0; i < ROWS; i++)
	{
		printf("|");
		for (size_t j = 0; j < COLS; j++)
		{
			printf("%c ", world[i][j]);
		}
		printf("|\n");
	}

}

void InitWorld(char world[ROWS][COLS])
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			world[i][j] = DEAD_CELL;
		}
	}
}

int main()
{
	char world[ROWS][COLS];
	char newWorld[ROWS][COLS];

	InitWorld(world);

	world[0][1] = LIVE_CELL;
	world[1][2] = LIVE_CELL;
	world[2][0] = LIVE_CELL;
	world[2][1] = LIVE_CELL;
	world[2][2] = LIVE_CELL;

	PrintWorld(world);

	int flag = TRUE;
	while (flag)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				int liveCells = GetLiveCellsAround(world, i, j);
				if (3 == liveCells && DEAD_CELL == world[i][j])
				{
					newWorld[i][j] = LIVE_CELL;
				}

				else if ((2 == liveCells || 3 == liveCells) && LIVE_CELL == world[i][j])
				{
					newWorld[i][j] = LIVE_CELL;
				}
				else
				{
					newWorld[i][j] = DEAD_CELL;
				}
			}
		}
		CopyWorld(world, newWorld);
		system("timeout 1");
		system("cls");
		PrintWorld(world);
	}
	return 0;
}

