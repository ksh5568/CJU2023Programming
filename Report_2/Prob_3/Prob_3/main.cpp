#include <stdio.h>
#define START 0000  // 시작에 대한 메크로 설정
#define END 9999  // 종료에 대한 메크로 설정

int main(void)
{
	int sys = 0;  // 시작 여부에 대한 변수 설정
	int num = 0;  // 입력 받는 정수에 대한 변수 설정
	int count = 0;  // 박수치는 횟수를 세는 변수 설정
	int i = 1;  // 반복 하는 수에 대한 변수 설정

	while (true)  // 무한반복문 실행
	{
		printf("Would you like to start the game?\n");  // "게임을 시작하시겠습니까?"를 출력
		printf("Enter 0000 to start and 9999 to end : ");  // 시작여부에 대해 입력 받음
		scanf_s("%d", &sys);  // 시작에 여부에 대한 입력 받은 변수를 저장

		if (sys == START)  // 시작에 대한 변수일 경우
		{
			printf("\n"); 
			printf("Enter the number : ");  // 정수를 입력 받음 
			scanf_s("%d", &num);  // 입력 받은 정수를 저장

			for (i = 1; i <= num; i++)  // i를 1로 초기화 하고 입력 받은 변수만큼 반복하고 1씩 증가한다.
			{
				if (i % 3 == 0)  // 박수 치는 조건을 설정
				{
					count++;  // 조건에 부합할때 마다 카운트 변수에 1씩 증가
				}
			}
			printf("Count of clap : %d\n", count);  // 박수를 친 횟수를 출력
			printf("\n");
		}
		if (sys == END)  // 종료에 대한 변수 일 경우
		{
			printf("\n");
			printf("Game Over\n");  // 게임 종료를 출력
			break;  // 프로그램 종료
		}
		if (sys != START && sys != END)  // 시작 혹은 종료에 대한 변수가 아닐경우
		{
			printf("\n");
			printf("Try again\n");  // 다시 시도하세요를 출려규
			printf("\n");
		}
	}
	return 0;
}