#include "Sudoku.h"

Sudoku::Sudoku(FILE *in)
{
	int i, j;
	int index=0;
	ecNum = 0;	
	fscanf(in, "%d ", &size);
	len = size*size;
	
// Initialization of row/col/sec Table
	rcs = new rcsTable(size);

// Initialization of Main Table
	mainTable = (int**)calloc(len+1, sizeof(int*));
	for(i=0; i<len+1; i++)
		mainTable[i] = (int*)calloc(len+1, sizeof(int));

	for(i=1; i<len+1; i++)
	{
		for(j=1; j<len+1; j++)
		{
			fscanf(in, "%d ", &mainTable[i][j]);
			// counting # of empty cells
			if(mainTable[i][j] == 0)
				ecNum++;
			else
				rcs -> mark(i,j,mainTable[i][j]);
		}
	}


// Initialization of empty cell list
	ecList = (emptyCell*)calloc(ecNum+1, sizeof(emptyCell));
	index = 0;
	for(i=1; i<len+1; i++)
	{
		for(j=1; j<len+1; j++)
		{
			if(mainTable[i][j] == 0)
			{
				index++;
				ecList[index].x = i;
				ecList[index].y = j;
			}
		}
	}


	/*
	for(i=1; i<size*size+1; i++)
	{
		for(j=1; j<size*size+1; j++)
			printf("%2d", mainTable[i][j]);
		printf("\n");
	}
	
	for(i=1; i<=ecNum; i++)
		printf("%2d,%2d\n", ecList[i].x, ecList[i].y);
	*/


// Complete Sudoku Table
	buildSudoku(0);

	//printf("%d\n", ecNum);

}

void Sudoku::buildSudoku(int depth)
{
	int i, j;
	int x, y;
	if(depth == ecNum)
	{
		printf(" (At least) One solution guaranteed!\n");
		printf(" One Possible solution (There may exist multiple solutions):\n\n");
		//FILE *out = fopen("output.txt","wt");
		for(i=1; i<size*size+1; i++)
		{
			for(j=1; j<size*size+1; j++)
				printf("%2d", mainTable[i][j]);
			printf("\n");
		}
		exit(0);
	}
	//if(depth>30)
	//printf("depth: %d\n", depth);
        x = ecList[depth+1].x;
	y = ecList[depth+1].y;
	for(i=1;i<size*size+1;i++)
	{
		if( rcs->ifOccupy(x,y,i) == 0 )
		{
			mainTable[x][y] = i;
			rcs -> mark(x,y,i);
			buildSudoku(depth+1);
			rcs -> unmark(x,y,i);
			mainTable[x][y] = 0;
		}
	}
	
}
int main()
{
	FILE *fp = fopen("input/input.txt", "rt");
	Sudoku *Table = new Sudoku(fp);

	return 0;
}




	/*
	rcsTable *table = new rcsTable(3);
	table->marker(9, 9, 9);
	//table->unmarker(9, 9, 9);
	std::cout << table->ifOccupy(9,9,9) << std::endl;

	std::cout << table->ifOccupy(1,8,8) << std::endl;
	*/
