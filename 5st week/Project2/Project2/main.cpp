#include <stdio.h>
#define AGE 25
#define CHESTSIZE 95
#define TWENTY 20
#define S_SIZE 85
#define M_SIZE 90
#define L_SIZE 100

int main(void)
{
	int age = AGE;
	int chest = CHESTSIZE;
	char size;

	if (age < TWENTY)
	{
		if (chest < S_SIZE)
		{
			size = 'S';
		}
		else if ((chest >= S_SIZE) && (chest < CHESTSIZE))
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
		if (chest < M_SIZE)
		{
			size = 'S';
		}
		else if ((chest >= M_SIZE) && (chest < L_SIZE))
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
