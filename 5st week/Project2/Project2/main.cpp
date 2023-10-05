#include <stdio.h>
#define AGE 25
#define chestsize 95
#define twen 20
#define Ssize 85
#define Msize 90
#define Lsize 100

int main(void)
{
	int age = AGE;
	int chest = chestsize;
	char size;

	if (age < twen)
	{
		if (chest < Ssize)
		{
			size = 'S';
		}
		else if ((chest >= Ssize) && (chest < chestsize))
		{
			size = 'M';
		}
		else
		{
			size = 'L';
		}
	}
	else
	{
		if (chest < Msize)
		{
			size = 'S';
		}
		else if ((chest >= Msize) && (chest < Lsize))
		{
			size = 'M';
		}
		else
		{
			size = 'L';
		}
	}
	printf("Size is %c.\n", size);

	return 0;
}