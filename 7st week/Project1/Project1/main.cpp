#include <stdio.h>

int main(void)
{
	int a = 0;  // 구구단 단수를 입력 받는 변수

	printf("Enter the singular number : ");  // 구구단 단수에 대한 변수를 입력 받기
	scanf_s("%d", &a);  // 구구단 단수에 대한 변수를 저장
	
	if(0<a,a<10)  // 1~9사이의 숫자만 활용하게 조건문 설정
		for (int i = 1; i < 10; i++)  // 9단 까지의 반복 설정
		{
			printf("%d * %d = %d\n", a, i, a * i);  // 구구단 계산 후 결과값 출력
		}
	else
	{
		printf("You entered it incorrectly\n"); // 1~9사이의 숫자가 아닐시 프로그램 종료
	}

	return 0;
}