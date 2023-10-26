#include <stdio.h>
#define TRI 0000  ／／ 정삼각형에 대한 메크로
#define RHO 1111  ／／ 마름모에 대한 메크로
#define EXIT 9999  ／／ 종료에 대한 메크로

int main(void)
{
	int sys = 0;  ／／ 도형 및 종료에 대한 변수 지정
	int len = 0;  ／／ 길이에 대한 변수 지정
	int i = 0;  ／／ 행에 대한 변수 지정
	int j = 0;  ／／ 열에 대한 변수 지정

	while (true)
	{
		printf("Enter 0000 for triangle or1111 for rhombus\n");  ／／ “삼각형은 0000을 마름모는 1111를 누르세요“출력
		printf("9999 for exit : ");  ／／ ”종료는 9999를 누르세요“
		scanf_s("%d", &sys);  ／／ 도형 및 종료에 대한 변수 저장

		if (sys == TRI)  ／／ 만약 삼각형에 대한 변수라면
		{
			printf("\n");
			printf("Please enter the length : ");  ／／ “길이를 입력하세요” 출력
			scanf_s("%d", &len);  ／／ 길이에 대한 변수에 저장

			for (i = 0; i < len; i++)  ／／ 입력 받은 수만큼 행을 반복
			{
				for (j = 0; j < len - i; j++)  ／／ 행에 대한 빈칸 출력 반복
				{
					printf(" ");  ／／ “빈칸” 출력
				}
				for (j = 0; j < 2 * i + 1; j++)  ／／ 행에 대한 “＊”출력 반복
				{
					printf("*");  ／／ “＊” 출력
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (sys == RHO)  ／／ 만약 마름모에 대한 변수라면
		{
			printf("Please enter the length : ");  ／／ “길이를 입력하세요” 출력
			scanf_s("%d", &len);  ／／ 길이에 대한 변수에 저장

			for (i = 0; i < len; i++)  ／／ 입력 받은 수만큼 행을 반복
			{
				for (j = 0; j < len - i; j++)  ／／ 행에 대한 빈칸 출력 반복
				{
					printf(" ");  ／／ “빈칸” 출력
				}
				for (j = 0; j < 2 * i + 1; j++)  ／／ 행에 대한 “＊”출력 반복
				{
					printf("*");  ／／ “＊” 출력
				}
				printf("\n");
			}

			for (i = 1; i < len; i++)  ／／ 입력 받은 수만큼 행을 반복
			{
				for (j = 0; j < i + 1; j++)  ／／ 행에 대한 빈칸 출력 반복
				{
					printf(" ");  ／／ “빈칸”츨력
				}
				for (j = 2 * len - 1; j > 2 * i; j--)  ／／ 행에 대한 “＊”출력 반복
				{
					printf("*");  ／／ “＊”출려
				}
				printf("\n");
			}
			printf("\n");
		}
		else if (sys == EXIT)  ／／ 만약 종료에 대한 변수라면
		{
			printf("Exit program");  ／／ ”프로그램 종료“ 출력
			break;  ／／ 프로그램 종료
		}
		else  ／／ 만약 모든 변수에 해당하지 않는 다면
		{
			printf(" Return again\n");  ／／ 다시하세요 출력
		}
	
	return 0;
}
