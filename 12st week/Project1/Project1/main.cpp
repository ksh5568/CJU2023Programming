#include <stdio.h>
#define FOUR 4
#define FIVE 5
#define SIX 6

int main(void)
{
	// 2차원 배열의 선언과 초기화
	int ary[5][6] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};
	int i = 0;
	int j = 0;

	for (i = 0; i < FOUR; i++)
	{
		for (j = 0; j < FIVE; j++)
		{
			ary[4][j] += ary[i][j];  // 각 행에 해당하는 총합 마지막열에 저장 
			ary[i][5] += ary[i][j];  // 각 열에 해당하는 총합 마지막행에 저장
			ary[4][5] += ary[i][j];  // 각 행, 열의 총합을 마지막 행, 열에 저장

		}
	}

	for (i = 0; i < FIVE; i++)
	{
		for (j = 0; j < SIX; j++)
		{
			printf("%5d", ary[i][j]);  // 각 행, 열에 맞게 출력
		}
		printf("\n");
	}
	return 0;
}
