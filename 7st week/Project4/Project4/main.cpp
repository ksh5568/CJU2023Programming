#include <stdio.h>
#define START 0000  // 시작하는 수를 메크로 설정
#define END 9999  // 종료하는 수를 메크로 설정

int main(void)
{
	int sys = 0;  // 시작 혹은 종료에 대한 변수
	int nA = 0;  // 입력받는 변수
	int i = 0;  // 조건문 반복 변수
	int sum = 0;  // 결과값 변수

	while (true)  // 무한 반복문 실행
	{
		printf("Enter the start(0000) and end(9999) : ");  // 시작은"0000"을 종료는 "9999"를 출력
		scanf_s("%d", &sys);  // 시작 혹은 종료에 대한 변수 저장

		if (sys == START)  // 시작에대한 변수일 경우
		{
			for (i = 0; i < 5; i++)  // 5번 반복
			{
				printf("Please enter the DNA number : ");  // DNA 숫자를 입력 받음
				scanf_s("%d", &nA);  // 입력 받은변수를 저장

				sum = sum + nA;  // 입력 받은 변수를 sum에 더한 후 저장
			}

			if ((sum % 5) == 3)  // 5로나누었을 떼 3이면
			{
				printf("Suspect\n");  // 용의자라고 출력
				printf("\n");
			}
			else  // 아닐경우
			{
				printf("Citizen\n\n");  // 시민으로 출력
				printf("\n");
			}
			continue;  // 프로그램 다시 반복
		}

		if (sys == END)  // 종료에 대한 변수일 경우
		{
			break;  // 프로그램 종료
		}
	}
	return 0;
}