#define WRONG_ARGUMETNS -1
#define FILE_OPEN_ERROR -2
#define FILE_CLOSE_ERROR -3

#define WORLD_SIZE 10 /*as descrived in the exercise*/ /*10 is nicer to print then 100*/
#define TRUE 1
#define FALSE 0


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"
#include <Windows.h> /*for sleeping function*/

void deleteLists(struct List* open, struct List* close, struct List* finalPath);
void printPath(int** world, struct List* pathList);
struct Node* AStar(int** world, struct List* open, struct List* close);
int calcH(int** world, int y, int x);
int isExistLowerF(struct List* list, struct Node* n);
struct Node* minF(struct List* l);
void freeWorld(int** world);
int** readWorld(FILE* f);
void flip(struct List* list, struct Node* dest);

int main(int argc, char* argv[])
{
	FILE* file;
	struct List* open;
	struct List* close;
	struct List* finalPath;
	struct Node* start;
	struct Node* end;

	int** world;

	if (argc!=2)
	{
		printf("the right usage is moshe <world file>");
		return WRONG_ARGUMETNS;
	}

	file = fopen(argv[1], "r");
	if (file==NULL)
	{
		printf("Error in openning the world file");
		return FILE_OPEN_ERROR;
	}

	/*initiate varriables*/
	world = readWorld(file);
	open = newList();
	start = newNode(NULL,0,0);
	/*start->g = world[0][0];*/
	listInsert(open, start);
	close = newList();
	finalPath = newList();

	end = AStar(world, open, close);
	flip(finalPath, end);
	printPath(world,finalPath);

	if (fclose(file) != 0)
	{
		printf("Error in closing the world file");
		return FILE_CLOSE_ERROR;
	}



	/*free varriables*/
	deleteLists(open,close,finalPath);
	freeWorld(world);

	
	getc(stdin);

	return EXIT_SUCCESS;
}
void deleteLists(struct List* open, struct List* close, struct List* finalPath)
{
	struct List* freeList;
	struct Node* runner;

	freeList = newList();
	runner = open->first;
	while (runner!=NULL)
	{
		if (!isInList(freeList, runner))
		{
			listInsert(freeList, runner);
		}
		runner = runner->next;
	}
	runner = close->first;
	while (runner != NULL)
	{
		if (!isInList(freeList, runner))
		{
			listInsert(freeList, runner);
		}
		runner = runner->next;
	}
	runner = finalPath->first;
	while (runner != NULL)
	{
		if (!isInList(freeList, runner))
		{
			listInsert(freeList, runner);
		}
		runner = runner->next;
	}
	deleteList(freeList);
	free(open);
	free(close);
	free(finalPath);
}
void printPath(int** world,struct List* pathList)
{
	char path[WORLD_SIZE][WORLD_SIZE];
	int i, j;
	struct Node* runner=pathList->first;
	int sum=0;
	for (i = 0; i < WORLD_SIZE; i++)
	{
		for ( j = 0; j < WORLD_SIZE; j++)
		{
			path[i][j] = '0';
		}
	}

	while (runner!=NULL)
	{
		path[runner->y][runner->x] = 'A';
		system("cls");/*clear the screen*/
		for (i = 0; i < WORLD_SIZE; i++)
		{
			for (j = 0; j < WORLD_SIZE; j++)
			{
				printf("%c ", path[i][j]);
				sum += world[i][j];
			}
			printf("\n");
		}
		runner = runner->next;
		Sleep(1000);
	}

	printf("\nTotal sum: %d\n",sum);


}
/*readWorld is similar to readBoard from life*/
struct Node* AStar(int** world,struct List* open,struct List* close)
{
	struct Node* n;
	struct Node* successor;
	int start_j;
	int i, j;
	while (!isListEmpty(open))
	{
		n = minF(open);
		deleteListMember(open,n,FALSE);
		/*calc where to start looking for neighbors*/
		i = n->y-1;
		if (i<0)
		{
			i = 0;
		}
		start_j = n->x - 1;
		if (start_j < 0)
		{
			start_j = 0;
		}
		/*generate neighbors*/
		for (; i <= n->y+1 && i<WORLD_SIZE; i++)
		{
			for (j = start_j; j <= n->x+1 && j<WORLD_SIZE; j++)
			{
				if (i==n->y&&j==n->x)
				{
					/*skip n*/
					continue;
				}
				successor = newNode(n,j,i);
				if (successor->x == WORLD_SIZE - 1 && successor->y == WORLD_SIZE - 1)
				{
					return successor;
				}
				successor->g = n->g + world[i][j];
				successor->h = calcH(world, i, j);
				successor->f = successor->g + successor->h;
				if (!isExistLowerF(open,successor)&& !isExistLowerF(close,successor))
				{
					listInsert(open, successor);
				}
			}
		}

		/*add n to closed list*/
		listInsert(close, n);

	}
	return NULL;
}
int calcH(int** world,int y, int x)
{
	int h=0;
	/*relativelty diagonal line to the end is the calculation for h*/
	while (x<WORLD_SIZE-1||y<WORLD_SIZE-1)
	{
		if (x<WORLD_SIZE-1)
		{
			x++;
		}
		if (y<WORLD_SIZE-1)
		{
			y++;
		}
		h += world[y][x];
	}
	return h;
}
int isExistLowerF(struct List* list,struct Node* n)
{
	struct Node* runner=list->first;
	while (runner!=NULL)
	{
		if (runner->x==n->x&&runner->y==n->y&&runner->f<n->f)
		{
			return TRUE;
		}
		runner = runner->next;
	}
	return FALSE;
}
struct Node* minF(struct List* l)
{
	struct Node* min = l->first;
	struct Node* n = l->first;
	while (n!=NULL)
	{
		if (n->f<min->f)
		{
			min = n;
		}
		n = n->next;
	}
	return min;
}
void freeWorld(int** world)
{
	int i;
	for (i = 0; i < WORLD_SIZE; i++)
	{
		free(world[i]);
	}
	free(world);
}
int** readWorld(FILE* f)
{
	char c;
	int** board;
	int i;
	int j;

	

	board = malloc(WORLD_SIZE*sizeof(int*));
	/*read board*/
	for (i = 0; i < WORLD_SIZE; i++)
	{
		board[i] = malloc(WORLD_SIZE*sizeof(int));
		for (j = 0; j < WORLD_SIZE; j++)
		{
			board[i][j] = 0;
			while ((c = fgetc(f))  && isdigit(c))
			{
				board[i][j] *= 10;
				board[i][j] += c - '0'; /*c is between 0 and 9*/
			}

		}
	}

	return board;

}
void flip(struct List* list,struct Node* dest)
{
	if (dest->parent==NULL)
	{
		listInsert(list, dest);
		return;
	}
	flip(list,dest->parent);
	listInsert(list, dest);
}