#include<stdlib.h>
class rcsTable
{
private:
	int size;

	int **row;
	int **col;
	int **sec;

public:
	rcsTable(int size);
	void mark(int x, int y, int val);
	void unmark(int x, int y, int val);
	int ifOccupy(int x, int y, int val);

};
