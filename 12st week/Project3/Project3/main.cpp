#include <stdio.h>
#include <stdlib.h>
#define ONE 1
#define min_num 2

int main(void)
{
	// 각 각의 변수 초기화
	int num = 0;
	int* res = 0;
	int count = 0;
	int i = 0;
	int j = 0;

	printf("Enter thr number : ");
	scanf_s("%d", &num);

	//저장공간 할당 및 예외 처리 구문
	res = (int*)malloc((num - ONE) * sizeof(int));
	if (res == NULL)
	{
		printf("Out od memory.\n");
		exit(1);
	}

	// 입력 받은 수의 배열 요소값 누적
	for (i = 0; i < (num - ONE); i++)
	{
		res[i] = i + min_num;
	}
	i = 0;


	// 소수 계산
	while (true)
	{
		while ((res[i] == 0) && (i < (num - min_num)))
		{
			i++;
		}

		if (i == (num - min_num)) break;

		for (j = i + ONE; j < (num - ONE); j++)
		{
			if (res[j] % res[i] == 0)
			{
				res[j] = 0;
			}
		}
		i++;
	}

	// 소수에 해당하는 수 및 'X' 출력
	for (i = 0; i < (num - ONE); i++)
	{
		if (res[i] != 0)
		{
			printf("%5d", res[i]);
			count++;
		}
		else
		{
			printf("%5c", 'X');
			count++;
		}
		if (count % 5 == 0)
		{
			printf("\n");
		}
	}

	free(res);

	return 0;
}