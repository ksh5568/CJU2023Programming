#include <stdio.h>

int main(void)
{
	int num = 0;  // 입력 받을 수 변수 설정
	int nA = 0;  // 첫번째수 변수 설정
	int nB = 1;  // 두번째수 변수 설정
	int nC = 0;  // 세번쨰수 변수 설정
	int i = 0;  // 반복할 수 변수 설정

	printf("Please enter the integer : ");  // 정수를 입력하세요를 출력
	scanf_s("%d", &num);  // 입력받은 정수를 변수에 저장

	while (num >= nA)  // 변수가 0보다 클 때 실행
	{
		if (num == nA)  // 변수가 0이면
		{
			printf("%d\t", nA); // 결과값 0으로 출력
			break;  // 프로그램 종료
		}
		else if (num == nB)  // 변수가 1이면
		{
			printf("%d\t", nB);  // 결과값 1으로 출력
			break;  // 프로그램 종료
		}
		else  // 0과 1일 아닐경우
		{
			for (i = 0; i < num; i++)  // i값 0으로 초기화 및 입력 받은 변수만큼 반복하고 1씩 증가
			{
				nC = nA + nB;  // 피보나치 수열을 이용한 공식
				nA = nB;
				nB = nC;

				printf("%d\t", nA);  // 피보나치수를 출력
				break;  // 프로그램 종료
			}
		}
	}
	printf("\n");

	return 0;
}
