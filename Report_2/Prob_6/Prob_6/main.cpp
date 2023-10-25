#include <stdio.h>
#define TRI 0000
#define RHO 1111
#define EXIT 9999

int main(void)
{
	int sys = 0;
	int len = 0;
	int i = 0;
	int j = 0;

	while (true)
	{
		printf("Enter 0000 for triangle or1111 for rhombus\n");
		printf("9999 for exit : ");
		scanf_s("%d", &sys);

		if (sys == TRI)
		{
			printf("\n");
			printf("Please enter the length : ");
			scanf_s("%d", &len);

			for (i = 0; i < len; i++)
			{
				for (j = 0; j < len - i; j++)
				{
					printf(" ");
				}
				for (j = 0; j < 2 * i + 1; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (sys == RHO)
		{
			printf("Please enter the length : ");
			scanf_s("%d", &len);

			for (i = 0; i < len; i++)
			{
				for (j = 0; j < len - i; j++)
				{
					printf(" ");
				}
				for (j = 0; j < 2 * i + 1; j++)
				{
					printf("*");
				}
				printf("\n");
			}

			for (i = 1; i < len; i++)
			{
				for (j = 0; j < i + 1; j++)
				{
					printf(" ");
				}
				for (j = 2 * len - 1; j > 2 * i; j--)
				{
					printf("*");
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (sys == EXIT)
		{
			printf("Exit program");
			break;
		}
		else
		{
			printf(" Return again\n");
		}
	}
	return 0;
}