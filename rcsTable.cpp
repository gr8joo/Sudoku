#include "rcsTable.h"
#include<iostream>
rcsTable::rcsTable(int size)
{
	int len = size*size;
	this -> size = size;
	row = (int**)calloc(len+1, sizeof(int*));
	col = (int**)calloc(len+1, sizeof(int*));
	sec = (int**)calloc(len+1, sizeof(int*));;

	for(int i=0; i < len+1; i++)
	{
		row[i] = (int*)calloc(len+1, sizeof(int));
		col[i] = (int*)calloc(len+1, sizeof(int));
		sec[i] = (int*)calloc(len+1, sizeof(int));
	}
}

void rcsTable::mark(int x, int y, int val)
{
	int secIndex = ( (x-1)/size )*size + (y-1)/size + 1;

	row[x][val] = 1;
	col[y][val] = 1;
	sec[secIndex][val] = 1;
}

void rcsTable::unmark(int x, int y, int val)
{
	int secIndex = ( (x-1)/size )*size + (y-1)/size + 1;

	row[x][val] = 0;
	col[y][val] = 0;
	sec[secIndex][val] = 0;
}	

int rcsTable::ifOccupy(int x, int y, int val)
{
	int secIndex = ( (x-1)/size )*size + (y-1)/size + 1;

	if(row[x][val] == 1 || col[y][val] == 1 || sec[secIndex][val] == 1)
		return 1;
	return 0;
}

