#include <stdio.h>
#define PRIME_NUMBER 2

int main(void)
{
	int num = 0;  // 입력 받을 수 변수
	int i = 0;  // 반복문 변수 지정
	int j = 0;  // 반복문 변수 지정
	int count = 0;  // 줄바꿈을 위한 카운트 변수

	printf("Enter an integer of 2 or more : ");  // 2이상의 숫자를 입력하세요 출력
	scanf_s("%d", &num);  // 입력 받은 변수 저장

	if (num < PRIME_NUMBER)  // 입력 받은 변수가 2보다 작을시
	{
		printf("Please check your number.\n");  // 숫자를 확인하세요 출력
	}
	else  // 아닐경우
	{
		for ( i = 2; i <= num; i++)  // i를 2로 저장 후 입력받은 변수 만큼 반복하면서 i를 1씩 증가
		{
			for ( j = 2; j <= i; j++)  // j를 2로 저장 후 i와 같거나 작을 경우까지 반복시키면서 j를 1씩 증가
			{
				if ((i % j) == 0)  // 나누었을 때 몫이 0일경우
				{
					if (i > j)  // i가 j보다 클경우
					{
						break;  // 프로그램 종료
					}
					else
					{
							printf("%5d", i);  // i를 5개 출력
							count++;  // 카운트 변수를 1증가
							if (count % 5 == 0)  // 카운트를 5로 나누었을 때 0이면
							{
								printf("\n");  // 줄바꿈 출력
							}
					}
				}
			}

		}
	}
	return 0;
}