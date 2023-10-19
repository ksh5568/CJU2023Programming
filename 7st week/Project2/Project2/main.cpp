#include <stdio.h>

int main(void)
{

	for (int i = 0; i < 5; i++)  // i행으로 진행되는 반복문 설정
	{
		for (int j = 0; j < 5; j++)  // j행으로 진행되는 반복문 설정
		{
			if (i == j)  // 우하향으로 별을 표시하는 조건문 설정
			{
				printf("*");
			}
			else if ( i + j == 4)  // 좌하향으로 별을 표시하는 조건문 설정
			{
				printf("*");
			}
			else  // 그외 공백으로 표시 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}