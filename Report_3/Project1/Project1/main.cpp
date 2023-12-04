#include <stdio.h>
#include <string.h>
#define MAX_NUM 12

// 두 정수를 바꾸기 위한 함수 정의
void swap(int* pa, int* pb)
{
	int temp = 0;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// 오름차순으로 정렬 시키기 위한 함수 정의
void line_up(int* sor)
{
	int temp = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < MAX_NUM; i++)
	{
		for (j = i; j < MAX_NUM; j++)
		{
			if (sor[i] > sor[j])swap(&sor[i], &sor[j]);
		}
	}
}

// 내림차순으로 정렬 시키기 위한 함수 정의
void line_down(int* sor)
{
	int temp = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < MAX_NUM; i++)
	{
		for (j = i; j < MAX_NUM; j++)
		{
			if (sor[i] < sor[j])swap(&sor[i], &sor[j]);
		}
	}
}

int main(void)
{
	// 각 변수 초기화
	int nRawArr[12] = { 232, 244, 878, 817, 754, 351, 481, 137, 115, 253, 986, 236 };
	char a_text[15];
	int k = 0;

	while (true)
	{
		// 프로그램 설명
		printf("Decide how to sort the given numbers.\n");
		printf("Enter the ascending' or 'descending'\n");
		printf("If you want to end the program, enter Exit\n");
		printf("=> ");
		scanf_s("%s", a_text, sizeof(a_text));

		// 오름차순일 경우
		if (strcmp(a_text, "ascending") == 0)
		{
			line_up(nRawArr);
			printf("The values ​​are sorted in ascending order.\n");

			// 정렬된 값 출력
			for (k = 0; k < MAX_NUM; k++)
			{
				printf("%5d", nRawArr[k]);
			}

			printf("\n");
		}
		// 내림차순일 경우
		else if (strcmp(a_text, "descending") == 0)
		{
			line_down(nRawArr);
			printf("The values ​​are sorted in descending order.\n");

			// 정렬된 값 출력
			for (k = 0; k < MAX_NUM; k++)
			{
				printf("%5d", nRawArr[k]);
			}

			printf("\n");
		}
		else if (strcmp(a_text, "exit") == 0)
		{
			printf("Exit the progran.\n");
			break;
		}
		// 두개의 경우가 아닐 시
		else
		{
			printf("Try again.\n");
		}

		printf("\n");
	}
	return 0;
}
