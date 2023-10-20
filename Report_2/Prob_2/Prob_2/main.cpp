#include <stdio.h>

int main(void)
{
	int num = 0;  // 입력 받을 수 변수 지정
	int nA = 0;
	int nB = 1;
	int nC = 0;
	int i = 0;

	printf("Please enter the integer : ");
	scanf_s("%d", &num);

	while (num >= nA)
	{
		if (num == nA)
		{
			printf("%d\t", nA);
			break;
		}
		else if (num == nB)
		{
			printf("%d\t", nB);
			break;
		}
		else
		{
			for (i = 0; i < num; i++)
			{
				nC = nA + nB;
				nA = nB;
				nB = nC;

				printf("%d\t", nA);
				break;
			}
		}
	}
	printf("\n");

	return 0;
}