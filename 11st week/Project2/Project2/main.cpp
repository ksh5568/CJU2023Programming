#include <stdio.h>
#define SIX 6  // '6'에 대한 숫자 메클로 설정

void input_nums(int* lotto_nums)  // 로또 번호를 입력하는 함수 정의
{
	// 각 변수 초기화
	int i = 0;
	int j = 0;

	for (i = 0; i < SIX; i++)
	{
		printf("Enter the number : ");
		scanf_s("%d", &lotto_nums[i]);

		if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				// 같은 수인 경우 "같은 수"라고 출력 후 "i"감소
				if (lotto_nums[i] == lotto_nums[j])   
				{
					printf("Same numer\n");
					i--;
					break;
				}
			}
		}
	}
}

void print_nums(int* lotto_nums)  // 저장된 값을 출력하는 함수 정의
{
	int i = 0;

	printf("lotto numer : ");
	for (i = 0; i < SIX; i++)
	{
		printf("%5d", lotto_nums[i]);
	}
	printf("\n");
}

int main(void)
{
	int lotto_nums[6];  // 로또 번호를 저장할 배열

	input_nums(lotto_nums);  // 입력 함수 호출
	print_nums(lotto_nums);  // 출력 함수 호출

	return 0;
}