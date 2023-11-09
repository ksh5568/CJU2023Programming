#include <stdio.h>

#define MAX_INT_ARRAY 10

int main(void)
{
	int nArrTest[MAX_INT_ARRAY] = {};
	int* pArrTest = nArrTest;

	printf("pArrTest:%x\n", pArrTest);

	for (unsigned int i = 0; i < MAX_INT_ARRAY; i++)
	{
		// nArrTest[i] = MAX_INT_ARRAY - i;
		// *(nArrTest + i) = MAX_INT_ARRAY - i;
		pArrTest[i] = MAX_INT_ARRAY - i;
		// *(pArrTest + i) = MAX_INT_ARRAY - i;
	}
	printf("\n");
	for (unsigned int i = 0; i < MAX_INT_ARRAY; i++)
	{
		// printf("nArrTest[%d] = %d\n", i, nArrTest[i]);
		printf("nArrTest[%d] = %d\n", i, *(nArrTest + i));
		// printf("nArrTest[%d] = %d\n", i, pArrTest[i]);
		// printf("nArrTest[%d] = %d\n", i, *(pArrTest + i));
	}
	printf("\n");
	for (unsigned int i = 0; i < MAX_INT_ARRAY; i++)
	{
		printf("nArrTest[%d] = %x\n", i, &nArrTest[i]);
		// printf("nArrTest[%d] = %x\n", i, *(nArrTest + i));
		// printf("nArrTest[%d] = %x\n", i, &pArrTest[i]);
		// printf("nArrTest[%d] = %x\n", i, *(pArrTest + i));
	}
	return 0;
}