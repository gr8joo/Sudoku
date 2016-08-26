#include "rcsTable.h"
#include <stdio.h>

class Sudoku
{
private:
	int size;
	int len;
	int **mainTable;
	
	int ecNum;
	struct emptyCell
	{
		int x;
		int y;
	};
	emptyCell *ecList;
	

public:
	Sudoku(FILE *in);
	rcsTable *rcs;
	
	void buildSudoku(int depth);
};
