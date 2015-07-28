#define WRONG_ARGUMENTS -1
#define FILE_OPEN_ERROR -2
#define FILE_CLOSE_ERROR -3
#define FILE_FORMAT_ERROR -4

/*using queue from the first exercise*/
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

/*graphical includes*/
#include <Windows.h> /*for sleeping*/

/*
format example:
1 0 1
0 0 0
1 1 1

where 1 stands for live
and   0 srands for dead
*/
void printBoard(int** board, int width, int height);
void calcChange(int**board, int width, int height, struct Queue* change);
void flip(int** board, struct Queue* q);
void freeBoard(int** board, int height);
int** readBoard(FILE* f, int* width, int* height);

int main(int argc, char* argv[])
{
	int width, height;
	int** board;
	FILE* file;
	struct Queue* changeQueue;

	if (argc!=2)
	{
		printf("the right usage is: life <board file>\n");
		return WRONG_ARGUMENTS;
	}
	/*open board file*/
	file = fopen(argv[1], "r");
	if (file==NULL)
	{
		printf("error in openning the board file\n");
		return FILE_OPEN_ERROR;
	}

	board = readBoard(file, &width, &height);

	/*close board file*/
	if (fclose(file) != 0)
	{
		free(board);
		return FILE_CLOSE_ERROR;
		printf("error in closing the board file\n");
	}
	if (board==NULL)
	{
		return FILE_FORMAT_ERROR;
	}

	changeQueue = newQueue();

	/*print initial state*/
	system("cls");/*clear the screen*/
	printBoard(board, width, height);
	Sleep(2000);

	/*game math*/
	while (1)
	{
		calcChange(board, width, height, changeQueue);
		flip(board,changeQueue);
		system("cls");/*clear the screen*/
		printBoard(board, width, height);
		Sleep(1500);
	}


	deleteQueue(changeQueue);
	freeBoard(board,height);
	return 0;
}
void printBoard(int** board, int width, int height)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
void calcChange(int**board, int width, int height, struct Queue* change)
{
	int i, j;
	int x, y;
	int start_x;
	int neighborsCount;
	for ( i = 0; i < height; i++)
	{
		for ( j= 0;  j <width;  j++)
		{
			/*check number of neighbors*/
			neighborsCount = 0;
			y = i - 1;
			if (y<0)
			{
				y = 0;
			}
			start_x = j - 1;
			if (start_x<0)
			{
				start_x = 0;
			}
			for (; y <= i+1 && y<height; y++)
			{
				for (x=start_x; x <= j+1 && x<width; x++)
				{
					neighborsCount += board[y][x];
				}
			}
			neighborsCount -= board[i][j]; /*ignore curretn cell in neighbors count*/
			/*check if cell needs to die or live*/
			switch (board[i][j])
			{
			case 0: 
			{
				if (neighborsCount==3)
				{
					queueInsert(change, i);
					queueInsert(change, j);
				}
				break; 
			}
			case 1:
			{
				if (neighborsCount<2||neighborsCount>3)
				{
					queueInsert(change, i);
					queueInsert(change, j);
				}
				break;
			}
			default:
				break;
			}
		}
	}
}
void flip(int** board, struct Queue* q)
{
	int x, y;
	while (queueSize(q) > 0)
	{
		x = queuePop(q);
		y = queuePop(q);
		board[x][y] = board[x][y] ^ 1; /*0^1=1 and 1^1=0, xor with 1 effectivly flips the content*/
	}
}
void freeBoard(int** board,int height)
{
	int i;
	for (i = 0; i < height; i++)
	{
		free(board[i]);
	}
	free(board);
}
int** readBoard(FILE* f,int* width,int* height)
{
	int size;
	char c;
	int** board;
	int i;
	int j;

	/*figure width*/
	*width = 0;

	while ((c=fgetc(f))&&c!='\n')
	{
		if (c == '0' || c == '1')
		{
			(*width)++;
		}
	}
	
	/*figure size*/
	fseek(f, 0, SEEK_SET);
	size = 0;
	while (!feof(f))
	{
		c = fgetc(f);
		if (c=='0'||c=='1')
		{
			size++;
		}
	}
	*height = size / *width;

	board = malloc((*height)*sizeof(int*));
	/*read board*/
	fseek(f, 0, SEEK_SET);
	for ( i = 0; i < *height; i++)
	{
		board[i] = malloc((*width)*sizeof(int));
		for (j = 0; j < *width; j++)
		{
			c = fgetc(f);
			/*c should be '0' or '1'*/
			switch (c)
			{
			case '0': board[i][j] = 0; break;
			case '1': board[i][j] = 1; break;
			default:
				return NULL;
			}
			c = fgetc(f); /*read the space to get it out of the way*/
		}
	}

	return board;

}